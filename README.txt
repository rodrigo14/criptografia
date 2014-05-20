Trabalho de Criptografia e Segurança de Redes
desenvolvido por:
- Rodrigo Gonçalves 11/0139356
- Alessandro Caetano 11/0057872

Professor: Luiz Laranjeira

-----------------------------------------------
Compilar projeto:
$ make

Depurar o projeto:
$ gdb criptografia

Executar o programa:
$ ./criptografia

Utilização:
- Selecione entre 3 métodos de criptografia:
1. Substituição (necessário chave)
2. Transposição (bloco de 8 caracteres / não é necessário chave)
3. Produto (Substituição + Transposição)
- Dentro dos métodos de criptogrfia, selecione o quebrador de código.

Obs: As entradas para os campos do textos e da chave estão preparadas
para qualquer tipo de caractere. No entanto, só serão cifradas os seguintes
caracteres: (a-z, A-Z, 0-9 e espaço em branco). Qualquer outro
caractere é ignorado pela lógica de cifragem.

