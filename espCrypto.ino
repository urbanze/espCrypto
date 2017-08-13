/*
 Name:		espCrypto.ino
 Created:	13/08/2017 19:34:34
 Author:	José morais
*/

#include <EspCrypto.h>

espCrypto esp;


void setup()
{
	String enc, dec;

	Serial.begin(115200);//Inicia a comunicação serial.


	esp.setKey("1234567890123456");//Adiciona a chave para encriptação, mantenha em segredo!
	

	enc = esp.encrypt("oi");//A função encrypt retorna uma string encriptada.
	Serial.println(enc);//Printa o criptograma (mensagem encriptada).

	dec = esp.decrypt(enc);//A função decrypt retorna uma string desencriptada.
	Serial.println(dec);//Printa a mensagem desencriptada.
	
	
}


void loop()
{

}
