# espCrypto

--Portuguese

Esta biblioteca, é uma abstração de outra biblioteca (https://github.com/spaniakos/AES). Criada no intúito para deixar a encriptação de fácil acesso e manipulação, e assim, permitir que mais pessoas, mesmo novatas, se acostumem com encriptação, algo essencial em IoT. A encriptação desta biblioteca é: AES128, AES192, AES256, diferenciando apenas o tamanho da chave.

Testada em Arduino UNO, MEGA e ESP8266. Para usa-la no ESP8266, veja o tutorial logo abaixo.

Para mais informações sobre a biblioteca de encriptação usada, clique aqui: https://github.com/spaniakos/AES



Instalação inicial


1-) Faça o download desta biblioteca (espCrypto) e também da biblioteca de encriptação (AES, https://github.com/spaniakos/AES).

2-) Instale ambas na sua pasta de bibliotecas, normalmente está na própria pasta da IDE Arduino, ou na pasta Arduino em seus documentos.



Arduino

Apenas instale as duas bibliotecas e use normalmente, para mais informações sobre os comandos, veja o arquivo espCrypto.ino .



ESP8266

Para o funcionamento da encriptação no ESP8266, é necessário alterar a pasta da PROGMEM, declarada no arquivo AES_config.h .

1-) Abra o arquivo AES_config.h com o bloco de notas ou algum editor de sua preferência.

2-) Edite esta parte:
#else
	#include <avr/pgmspace.h>
#endif


para ficar assim:
#else
	#include <pgmspace.h>
#endif

3-) Salve o arquivo e já esta pronto para uso.
