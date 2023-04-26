# Reprodutor de som com base em texto

## Requisitos de implementação:

### Controlador da Aplicação
Irá controlar o estado atual da aplicação, ou seja, a janela da aplicação em que o usuário se encontra, se o arquivo de reprodução está disponível, etc.

### Interface Gráfica
Tem por objetivo realizar a interface entre o usuário e a aplicação. Irá contar com caixas de texto e botões de navegação que irão alterar o estado do aplicativo no `Controlador da Aplicação`.

### Gerenciador de texto
Responsável por receber entradas do usuário em formato texto, seja por meio de arquivos de texto ou por meio de entrada em caixas de texto designadas para o usuário por meio da `Interface Gráfica`.

### Analisador de texto
Realizará o 'parsing' do texto dado como entrada pelo `Gerenciador de Texto`. Irá mapear o texto para um formato de arquivo sonoro, utilizado posteriormente para reprodução.

### Interface de reprodução de áudio
Reproduzirá o arquivo gerado pelo `Analisador de Texto` utilizando uma API externa.
