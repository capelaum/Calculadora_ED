
<h1 align="center">
  Calculadora_ED :1234:
<h1/>
  
<h3 align="center">
  Projeto da matéria de Estrutura de Dados pela UnB - Semestre 2018/01<br> <br>
  Programa de Calculadora e Resolução de Expressões Aritméticas utilizando uma pilha de dados em linguagem C. 
<h3/>

Resolve expressões aritméticas validando a expressão passada de forma padrão infixa e através da transformação para a Notação Polonesa Reversa (NPR),
consegue realizar os cáculos.
<br>

## Introdução

<p>
  Logo no início do ciclo escolar o estudante é apresentado ao maravilhoso mundo da matemática,
  assim que domina as operações básicas o aluno começa a estudar expressões numéricas. A forma
  mais comum de se representar expressões numéricas é a forma infixada, que é quando as operações
  estão entre dois operandos (Ex. 7+5), porém tal notação quando em expressões muito grandes pode
  ser um pouco confusa, isso se deve principalmente a dupla interpretação que algumas precedências
  de sinais podem possuir. Além de evitar tais confusões usamos parênteses para indicarmos quais
  conjuntos de operações devem ser realizadas primeiro.
<p/>

<p>
  Mas imagine que existisse uma forma de representar expressões numéricas complexas sem o uso
  de parênteses e sem a possibilidade de haver confusão quanto a ordem das operações?  
<p/>

<p>
  Existem duas formas de representações alternativas que solucionam este problema. Uma delas é
  conhecida como Notação Polonesa Reversa(RPN) também chamada de notação pósfixada, inventada
  pelo filósofo e cientista da computação australiano Charles Hamblin em meados dos anos 1950.
  Ela deriva da segunda forma de representação a notação polonesa ou também notação préfixada,
  introduzida em 1920 pelo matemático polonês Jan Lukasiewicz. Hamblin apresentou seu trabalho
  numa conferência em Junho de 1957, e o publicou em 1957 e 1962.
<p/>

## Descrição

### 2.1 Problema

<p>
  Os préfixos \pre", \pos" e \in" referem-se à posição relativa do operador em relação aos dois operandos
  da expressão. O que dificulta a avaliação de expressões na forma infixa, por um sistema
  computacional, é a existência de prioridades entre os operadores, como por exemplo A + B * C,
  e a existência de parênteses que modificam esta prioridade, como por exemplo (A + B) * C. Estes
  problemas não são encontrados nas outras representações (prefixa e posfixa), uma vez que a ordem de
  execução das operações é estabelecida apenas pela ordem dos operandos e operadores na expressão.
<p/>

- Notação prefixa (notação polonesa): + A B
- Notação infixa: A + B
- Notação pósfixa (notação polonesa reversa): A B +

### 2.2 Programa

<p>
  Neste trabahlo deverá ser desenvolvido um programa com dois modeos de operação descritos a seguir:
<p/>

#### Resolução de Expressão

- O programa receberá como entrada uma expressão na forma usual (infixa);
- Primeiramente, o programa deverá analisar a validade da expressão infixa;
- Caso seja válida, o programa transformará a expressão da forma infixa para a forma
posfixa;
- Finalmente, o programa calculará o resultado da expressão;

#### Calculadora

- O programa aguarda pela entrada dos números ou operações;
- Quando um número é digitado ele é empilhado, a pilha deve ser sempre exibida em tela
- Quando uma operação é digitada os operandos são desempilhados, a operação realizada e
seu resultado empilhado novamente;
- Caso a operação seja inválida ou a quantidade de operandos insuficiente uma mensagem
de erro deve ser impressa;

<p>
  Um menu deverá ser desenvolvido apresentando as duas opções de operação ao usuário. Estruturas de
  repetição devem ser utilizadas afim de permitir ao usuário navegar entre os dois modos de operação
  sem que tenha que finalizar o programa.
<p/>

#### Para Saber mais consulte o documento em pdf - [Trabalho1_ED.pdf](https://github.com/capelaum/Calculadora_ED/blob/master/Trabalho1_ED.pdf)
