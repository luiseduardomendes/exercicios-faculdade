## Choosing Message

Uma mensagem é uma expressão lógica que é passada a um método. Esta é capaz de de decidir o curso de execução de um programa, o que ocasiona uma complexificação no fluxo de execução de um software.

Um caso de utilização de uma mensagem é no caso da mensagem de escolha, ou seja, nesse caso, uma escolha entre diferentes implementações. 

Essa escolha pode ser feita a partir do polimorfismo de uma classe, de modo que, a depender do parâmetro inserido no método, diferentes fluxos de execução serão tomados.

Isso permite a futura extensão do código posteriormente, com inclusão de novos fluxos de execução de modo simples.

Contudo, mensagens de escolha podem ser de difícil leitura, nos casos em que o leitor tenha que entender o funcionamento de diversas classes para compreender com precisão o fluxo de execução. Além disso, existem casos em que a utilização de mensagens de escolha é desnecessária, em casos em que não há ou há uma pequena variação na computação.