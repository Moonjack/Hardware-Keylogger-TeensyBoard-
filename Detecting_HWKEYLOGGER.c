#include <iostream >
#include <stdio.h>
#include <libusb−1.0/libusb.h>

using namespace std;


#define ENDPOINT_IN 0 0x81 // IN Endpoint
int main ( ) {
unsigned char buffer[8];
buffer[0] = ’f’;
buffer[1] = ’f ’; // P u f f e r a u s f ü l l e n , damit man
		  //ä n d e r u n g e n s i e h t
buffer[2] = ’f’;
buffer[3] = ’f ’;
buffer[4] = ’f’;
buffer[5] = ’f’;
buffer[6] = ’f’;
buffer[7] = ’f’;

int len = 0 ;
libusb_device_handle ∗ check ; // handle
libusb_device ∗ dev ;
libusb_context ∗ ctx = NULL;
int r ;
ssize_t cnt;
r = libusb_init(&ctx) ; //Session wird  erstellt
check = libusb_open_device_with_vid_pid ( ctx , 0x0461 , 0x4dbf ) ; 
//Gerät wird geöffnet

 if(check == NULL)
{ cout << ”ERROR” << endl; 
//Gerät konnte nicht geöffnet werden
return 1;
}
/∗ Prüfen ob die Schnittstellen vom Kernel−Treiber benutzt
werden ∗/
int act1 = libusb_kernel_driver_active(check, 0);
int act2 = libusb_kernel_driver_active(check, 1) ;

cout << ”ACTIVE 0 ” << act1 << endl ;
cout << ”ACTIVE 1 ” << act2 << endl ;
 /∗ Kernel−Treiber wird von der Schnittstelle gelöst ∗/
  int result = libusb_detach_kernel_driver(check, 0 );
  int resultx0 = libusb_detach_kernel_driver(check, 1);

 cout << ”0 detached” << result << endl ;
 cout << ”1 detached” << resultx0 << endl ; /

  /∗ Konfiguration vom USB Gerät ∗/
  int re = libusb_set_configuration(check,1) ;
  /∗ Schnittstelle wird von dieser Software beansprucht ∗/
  int claim0 = libusb_claim_interface(check,0) ;
  int claim1 = libusb_claim_interface(check,1) ;

 /∗ USB Reset wird  durch geführt , falls die Tastatur beim  ersten Interrupt −Transfer kein Reset durchgeführt ∗/
 libusb_reset_device(check) ;
/∗ Interrupt −Transfer wird durchgeführt ∗/
libusb_interrupt_transfer(check , ENDPOINT_IN, buffer , sizeof(buffer) , &len , 0 ) ;


 /∗ Byte wird aus dem Puffer gelesen ∗/
 for ( int i = 0 ; i < 8 ; i ++)
 printf(”%x” , buffer[i] );
 cout << endl;
 /∗ Schnittstelle wird freigegeben ∗/
 libusb_release_interface(check, 0) ;
 libusb_release_interface(check, 1 );
  /∗ Kernel−Treiber benutzt wieder die Schnittstelle ∗/
 libusb_attach_kernel_driver(check, 0);
 libusb_attach_kernel_driver(check, 1);
/∗ Handle wird geschlossen ∗/
 libusb_close(check) ;
 /∗ Session wird geschlossen ∗/
