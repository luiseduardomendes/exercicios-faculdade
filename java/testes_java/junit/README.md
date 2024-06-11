## Relatório do trabalho de desenvolvimento de testes

Durante o desenvolvimento pude perceber alguns conceitos que não tinha visto durante as leituras realizadas. Uma delas foi que, a medida que os casos de teste iam sendo desenvolvidos, se tornou necessário, para continuar entendendo cada caso de teste, separar os testes que se relacionavam entre si, como os testes de valores negativos ou iguais a zero, que deveriam ser separados, por motivos de compreensão, dos testes que verificavam se a classificação de um dado triângulo tinha sido conforme o esperado. Além disso, também notei que, diferentemente da minha primeira abordagem, não valeria a pena realizar um laço de repetição com vários testes, uma vez que dificultaria a compreensão do que está sendo testado no momento que um erro foi encontrado, o que dificultaria o diagnóstico. Para o caso de ser necessário (ou desejado) um laço de repetição de uma bateria de testes, os testes ainda deveriam mostrar o estado do sistema, para tornar possível o diagnóstico de um erro, o que entraria, na maioria das vezes, em casos de testes randomizados, que foi estudado durante a disciplina e trabalhada nas leituras obrigatórias. Pude perceber também como pensar nos testes anteriormente ao desenvolvimento do código auxilia na forma que o software é desenvolvido, com base no TDD (Test Driven Development). Por fim, notei que, ao executar os testes, a ferramenta utilizada é extremamente poderosa para encontrar falhas e que, uma vez feitos os testes, estes poderiam ser reutilizados posteriomente, no caso de uma possível refatoração, a fim de assegurar a inalteração do software.