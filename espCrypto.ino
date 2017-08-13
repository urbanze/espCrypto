/*
 Name:		espCrypto.ino
 Created:	13/08/2017 19:34:34
 Author:	José morais
 
 Exemplo de encriptação usando espCrypto.
*/

#include <EspCrypto.h>

espCrypto esp;


void setup()
{
	Serial.begin(115200);//Inicia a comunicação serial.


	esp.setKey("1234567890123456");//Adiciona a chave para encriptação, mantenha isto em segredo!


	Serial.println(esp.encrypt("oi"));//Printamos a String criptografada retornada pela função encrypt.
}


void loop()
{

}
