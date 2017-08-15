# espCrypto

--Portuguese

Esta biblioteca, é uma abstração de outra biblioteca (https://github.com/spaniakos/AES). Criada no intúito para deixar a encriptação de fácil acesso e manipulação, e assim, permitir que mais pessoas, mesmo novatas, se acostumem com encriptação, algo essencial em IoT. A encriptação desta biblioteca é: AES128, AES192, AES256, todas em modo ECB, diferenciando apenas o tamanho da chave.

Testada em Arduino UNO, MEGA e ESP8266. Para usa-la no ESP8266, veja o tutorial logo abaixo.

Para mais informações sobre a biblioteca de encriptação usada, clique aqui: https://github.com/spaniakos/AES

Para mais informações sobre encriptação e segurança de dados, clique aqui: http://portal.vidadesilicio.com.br/seguranca-de-dados-com-aes/

A biblioteca esta em desenvolvimento e também não oferece garantia nenhuma de funcionamento. Qualquer BUG, por favor reporte!



# Instalação inicial


1-) Faça o download desta biblioteca (espCrypto) e também da biblioteca de encriptação (AES, https://github.com/spaniakos/AES).

2-) Instale ambas na sua pasta de bibliotecas, normalmente está na própria pasta da IDE Arduino, ou na pasta Arduino em seus documentos.



# Arduino

Apenas instale as duas bibliotecas e use normalmente, para mais informações sobre os comandos, veja as instruçoes abaixo.



# ESP8266

Para o funcionamento da encriptação no ESP8266, é necessário alterar a pasta da PGMSPACE, declarada no arquivo AES_config.h .

1-) Abra o arquivo AES_config.h com o bloco de notas ou algum editor de sua preferência.

2-) Edite esta parte:

	#include <avr/pgmspace.h>


para ficar assim:

	#include <pgmspace.h>



3-) Salve o arquivo e já esta pronto para uso.

Para mais informações sobre os comandos, veja as instruçoes abaixo.


# Instruções da biblioteca

espCrypto::setKey(String key)

A função setKey serve para adicionar a chave de encriptação nos algoritimos, os valores de chaves são: 16, 24 ou 32 caracteres. Exemplo: setKey("1234567890123456");

-----------------------------------------------------------------------------------------------------------------------

espCrypto::encrypt(String text)

A função encrypt, retorna uma String encriptada. O texto precisa ter menos que 16 caracteres. Exemplo: encrypt("oi"); irá retornar "e2de32b25387c84b713a956f062e9bb9" com a chave usada.

-----------------------------------------------------------------------------------------------------------------------

espCrypto:decrypt(String text)

A função decrypt, retorna a String desencriptada. O Texto precisa ter 32 caracteres, sem espaços ou coisas do tipo. Exemplo: decrypt("e2de32b25387c84b713a956f062e9bb9"); irá retornar "oi" com a chave usada.

-----------------------------------------------------------------------------------------------------------------------

sha1(String text)

A função sha1, retorna o hash da String. Hash são uma ótima escolha para senhas, já que é IRREVERSIVEL. Um método para utiliza-la é gerar o Hash de uma senha e comparar com outro Hash, se forem iguais, logo, a senha é a mesma. Exemplo: sha1("oi"); irá retornar "ef67e0868c98e5f0b0e2fcd9b0c4a3bad808f551" e é IMPOSSÍVEL (atualmente) retornar a mensagem original, o único método para descobrir é via Brute-Force e Word-List.

Para mais informações sobre Hash, clique aqui: https://pt.wikipedia.org/wiki/Fun%C3%A7%C3%A3o_hash
