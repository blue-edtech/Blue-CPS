# Aula #1 - Deep Learning - Parte 1

Por <a href="https://www.youtube.com/paulosalvatore" target="_blank">Paulo Salvatore</a> - Head de Produtos <a href="https://blueedtech.com.br/quem-somos/" target="_blank">@Blue Edtech</a> & Chanely Marques - Eterna Aprendiz <a href="https://blueedtech.com.br/quem-somos/" target="_blank">@Blue Edtech</a>

Olá :wave:, seja bem-vindo(a) ao nosso primeiro vídeo desta série. Nosso objetivo é introduzir o conceito de rede neural, neurônios, aprendizagem profunda, funções de ativação, algoritmo de Backpropagation e aplicação prática com TensorFlow Playground.

## Introdução

Antes de mergulharmos no **Deep Learning** (D.L. - aprendizagem profunda) é necessário sabermos que ele está dentro de uma estrutura de conhecimentos da **Inteligência Artificial** (I.A.).

![Aula01_Figura01](imagens/Aula01_Figura01.png)

A I.A. começou sua evolução pela década de 50 e faz parte do campo de estudos da Ciência da Computação que se combina a conjuntos de dados robustos para permitir a resolução de problemas. Alan Turing, muitas vezes chamado de "pai da ciência da computação", frequentemente questionava se as máquinas seriam capazes de pensar. A partir daí definiu que a I.A. seria categorizada como <a href="https://www.ibm.com/br-pt/cloud/learn/what-is-artificial-intelligence" target="_blank">"sistemas que agem como humanos"</a>.

O **Machine Learning** (M.L. - aprendizagem de máquina) veio um pouquinho depois, se tornando uma técnica de aprendizagem de máquina para que ela reconheça padrões e aprenda em cima de um grande conjunto de dados e a partir deste aprendizado tomamos decisões, fazemos previsões, entre outros.

O Deep Learning fez sua primeira aparição entre as décadas de 70 e 80 e começou a se popularizar a partir de 2010. É um método que incorpora redes neurais em camadas para que a aprendizagem a partir dos dados seja feita de forma iterativa.

![Aula01_Figura02](imagens/Aula01_Figura02.png)

Tanto M.L. quanto o D.L recebem informações na camada de **Input** (entrada) e, baseados nestas informações, tomam decisões ou fazem alguma previsão na camada de **Output** (saída), comparando aos dados que já eram conhecidos.

No processo de M.L., os dados entram pela camada de **Input**, e a extração deles é feita completamente por um Ser Humano. Estruturados e organizados, estes dados são classificados por uma máquina, gerando um resultado na camada de **Output**.

> ***_NOTA :clipboard: :pencil2: :_***  O processo de extração se caracteriza por observar, analisar e estruturar o conjunto de dados recebidos na camada **Input**.

> ***_NOTA :clipboard: :pencil2: :_***  O processo de classificação é feito inteiramente por uma máquina, através de uma ou um conjunto de fórmulas matemáticas classificando todas as features extraídas.

No processo de D.L., os dados entram pela camada de **Input**, e os processos de extração e classificação das features, são feitos inteiramente pela máquina gerando o **Output**. A grande vantagem é que ele pode nos trazer informações interessantes e/ou relevantes, que poderiam passar despercebidas pelo Ser Humano.

> **_Obs.:_** Para ambos os processos, os dados precisam ser preparados por um Ser Humano para entrar no processo de aprendizagem.

Para que estes conceitos fiquem mais claros, assista aos vídeos a seguir:

- Este carro autônomo usa o D.L. para saber se objetos que passam no campo de visão são carros ou não: <a href="https://www.youtube.com/watch?v=mUV5ZwIC9_g&feature=youtu.be" target="_blank">Carro Autônomo</a>.

- No reconhecimento de voz as palavras são identificadas através do Input de vários arquivos de voz: <a href="https://www.youtube.com/watch?v=NaqZkV_fBIM&feature=youtu.be" target="_blank">Reconhecimento de Voz</a>.

- Projeto GauGAN da Nvidia que transforma desenhos em paisagens usando Redes Neurais: <a href="https://www.youtube.com/watch?v=p5U4NgVGAwg" target="_blank">GauGAN</a>.

- Poder de análise de dados entre CPU vs. GPU: <a href="https://www.youtube.com/watch?v=-P28LKWTzrI" target="_blank">CPU vs. GPU</a>.

### Formas de Análise de Input de Dados

Neste exemplo, somos um algoritmo de I.A. com o objetivo de entender informações:

![Aula01_Figura03](imagens/Aula01_Figura03.png)

A letra `A` pode ser entendida de diversas formas:

- Ao analisar sua imagem, independente da forma que foi escrita
  - No caso do computador, uma imagem é um conjunto de pixels
  - No caso do ser humano, uma imagem é gerada pelos nossos olhos e processada pelo cérebro
- Ouvindo-a sendo dita
  - No caso do computador, um áudio é um arquivo que contém várias faixas de frequência (medidas em Hertz) e intensidades diferentes para cada valor de frequência
  - No caso do ser humano, um som é interpretado por nossos ouvidos e processado pelo cérebro

Para que, ao final do processo, tenhamos a informação que aquela letra representa, precisamos transformá-la, pois, afinal, não é tão prático usar um conjunto de pixels ou um arquivo de áudio em um programa de computador, trabalhar diretamente com a informação é muito melhor e mais prático.

O mesmo processo é feito para dígitos numéricos:

![Aula01_Figura04](imagens/Aula01_Figura04.png)

O dígito pode ter sido escrito à mão, digitado em um computador ou extraído de uma imagem. Como algoritmos, precisamos ler estes **Inputs** para saber que o dígito é um `5` e não uma representação dele.

Este mesmo processo de `Input -> Análise dos dados -> Output` é feito pelo nosso cérebro o tempo todo. Através da rede neural, espalhada por todo o corpo é captamos as informações do ambiente, as transformamos em estímulos sensoriais que são entendidos e traduzidos pelos neurônios no cérebro que  nos devolve a informação em forma de sensação de tato, audição, visão ou paladar e a partir disso tomamos alguma decisão.

## Preparação da Rede Neural

<13:08> - Paulo, me empolguei um pouco aqui porque sou perdidamente louca por neurociências :B <3

Para que o cérebro consiga de fazer todas as coisas que hoje sabemos que é capaz de fazer, podemos imaginar que um único neurônio têm sua estrutura e forma de funcionar bastante complexa. 

Por hora não vamos nos servir desta complexidade, mas sim de sua simplicidade funcional: receber e transmitir impulsos elétricos, ou seja, receber e transmitir informações.

![Aula01_Figura06](imagens/Aula01_Figura06.png)

A estrutura básica de um neurônio consiste em:

- <b>Dendritos</b>: é por aqui que as informações entram - `Inputs`,
- <b>Corpo celular</b>: recebidas as informações, as mesmas serão analisadas, processadas e decididas quanto ao destino,
- <b>Axônio envolto de ilhas de bainha de mielina</b>: fio condutor responsável por transmitir as informações do corpo celular para o axônio terminal, e;
- <b>Axônio terminal</b>:  é por aqui que as informações saem - `Outputs`.

Para que as informações saiam do axônio terminal `A` para o dendrito do axônio `B`uma estrutura chamada <b>sinapse</b> - que pode ser química ou elétrica - é ativada através do estímulo que sai do axônio terminal de `A` para o dendrito de `B`.

Graças à essas sinapses nosso cérebro é capaz de processar 11 bilhões de bits por segundo através de conexões paralelas entre todos os neurônios.

> ***_Curiosidade_***: Uma sinapse se forma entre um neurônio do cérebro com outro neurônio do cérebro. Quando um neurônio do cérebro precisa falar com uma célula muscular para ativar qualquer músculo no corpo, a estrutura se chama <b>junção neuromuscular</b>.

Este conceito de processar informações paralelamente é bastante conhecido por nós, o <b>processamento paralelo</b>, que explora e usa simultaneamente várias unidades de processamento (CPU's).

Por exemplo, ao ouvirmos a letra `A`, a informação do som em Hz é transmitida pelos condutos auditivos e captada pelos neurônios especializados. Estes captadores formam uma cascata de estímulos elétricos ativando o processamento paralelo nas áreas cerebrais especializadas em audição, para que finalmente o reconhecimento da informação `A` seja feito e devolvido para nós em forma de "Hmm, isso que eu ouvi é a letra `A`, eu a conheço!".

Este mesmo processo é feito para todas as informações que captamos do ambiente através dos 5 sentidos.

> Por hora, queremos que você guarde o seguinte: podemos  fazer uma analogia de tudo que vimos acima a um único neurônio de máquina. Na máquina este neurônio realiza uma função muito simples que é a de armazenar um número aleatório entre 0 e 1.

![Aula01_Figura05](imagens/Aula01_Figura05.png)

## Representação Matemática

<16:59>

Vamos observar e estudar com calma a figura abaixo:

![Aula01_Figura07](imagens/Aula01_Figura07.png)

Paralelamente à estrutura funcional de um neurônio, esta representação matemática possui uma região que recebe <b>Inputs</b> (dendrito), outra que <b>analisa, processa e envia as informações</b> (corpo celular e axônio) e por fim, a que faz o <b>Output</b> (axônio terminal).

Vamos trabalhar novamente o exemplo da letra `A`: a informação entrará na camada Roxa de Input, será processada na camada Laranja, e sairá pela camada Verde de Output nos trazendo o resultado se a letra `A` foi ou não identificada.

> ***Importante :bangbang: :*** Neste momento precisamos ter muito claro que a camada de Input é por onde entram as informações e a camada de Output é por onde elas saem.

### Processamento das informações

Dentre todos os conceitos de uma rede neural, certamente o entendimento sobre <b>pesos (Wheights)</b> e <b>valores propagados (Bias)</b> são os de fundamental importância.

Quando a informação é transmitida da camada de Input para a de processamento, os pesos são aplicados à esta informação, somados e carreados adiante para uma função de ativação juntamente com os valores de Bias.

> ***_NOTA :clipboard: :pencil2: :_***  Os pesos são coeficientes da equação que estamos tentando resolver naquele momento.

> ***_NOTA :clipboard: :pencil2: :_***  Os valores de Bias consistem em vetores adicionados ao produto dos Inputs e dos pesos que compensam os resultados colocando-os mais ou menos para o positivo ou negativo.

Cada informação que entra pela camada de Input é <b>multiplicada</b> por um <b>peso</b> que recebe um valor aleatório.  

![Aula01_Figura08](imagens/Aula01_Figura08.png)

Por exemplo, vamos imaginar que recebemos as letras `A` com o valor de `2` e `B` com o valor de `5` pela camada de Input. 

O `peso A` recebe o valor de `3` e `peso B` recebe o valor de `6`.

:key: :bulb: O <b>somatório</b> será o total de: <b>(`A` * Peso A) + (`B` * Peso B) = 36 </b>.

Agora podemos adicionar um valor de bias que pode ser um número positivo ou negativo, no caso `-2`

:key: :bulb: O <b>total</b> do processamento será: <b>(somatório + bias) = 34</b>.

Com o resultado total em mãos ele será passado por uma função de ativação e a partir dela teremos um novo número que será passado para a camada de Output.

Vamos entrar mais a fundo em cada uma dessas partes?

<21:55>

## Camada de Entrada (Input)

Para aprofundarmos nosso estudo e deixá-lo mais tangível, vamos falar sobre um banco de dados bastante específico chamado <b>MINIST</b> que contém imagens binárias de dígitos escritos à mão por diversas pessoas.

![Aula01_Figura09](imagens/Aula01_Figura09.png)

> ***Importante*** :bangbang: : Identificar o dígito de qualquer uma destas imagens pelo nosso Deep Learning é uma tarefa análoga a um 'Hello World!'. Atente-se à maldição. :jack_o_lantern:

O MIINST tem um primo evoluído chamado <b>Fashion-MINIST</b>, um banco de dados de imagens de artigos da [Zalando](https://github.com/zalandoresearch/fashion-mnist). Possui um conjunto de 60.000 exemplos de treinamento para aprendizagem de máquina e um conjunto de teste de 10.000 exemplos. Cada exemplo é uma imagem em tons de cinza de 28px por 28px, associada a um rótulo de 10 classes.

![Aula01_Figura10](imagens/Aula01_Figura10.png)

No vídeo-exemplo abaixo podemos analisar como um algoritmo observa um conjunto de dados com artigos de moda em geral e os posiciona por similaridade.

![Aula1_Gif01](imagens/Aula01_Gif01.gif)

<23:57>

Das 70.000 imagens que podemos encontrar no MINIST, vamos pegar uma delas para o nosso exercício que contém 28px de largura por 28px de altura totalizando 784px organizados em linhas e colunas.

![Aula01_Figura11](imagens/Aula01_Figura11.png)

Cada ponto na imagem é análogo a um neurônio contendo números que vão do intervalo de 0 a 1.

![Aula01_Figura12](imagens/Aula01_Figura12.png)

Quanto mais próximo do número `1` o neurônio se encontra, mais forte está sendo ativado. Veja na imagem que o branco se evidencia com o número `1.0` dentro dele.

Quanto mais próximo do número `0` o neurônio se encontra, menos ativado está sendo. Veja na imagem que o preto se evidencia com o número `0.0` dentro dele.

Entre `0` e `1` temos o neurônio parcialmente ativado. Veja na imagem que o branco começa a se evidenciar com o número `0.7 ou 0.8` dentro dele.

> ***_NOTA :clipboard: :pencil2: :_***  No dataset do MINIST todas as imagens acompanham o significado do que ela representa. No nosso exemplo a imagem recebe o significado `3`.

Para uma análise em que o Input receba um arquivo de áudio, a análise será realizada da mesma forma observando a frequência e sua intensidade.

![Aula01_Figura13](imagens/Aula01_Figura13.png)

Cada frequência carrega consigo uma intensidade, gerando um Output que pode ser uma letra qualquer ou uma frase, por exemplo.

## Modelo de Rede Neural

<27:47>

Semelhante à representação do neurônio, o modelo de rede neural carrega a mesma estrutura.

![Aula01_Figura14](imagens/Aula01_Figura14.png)

- Camada de entrada (Input) - é a primeira camada da rede neural que recebe os valores de entrada e os passa para a próxima cada sem aplicar pesos ou bias. 

  No nosso exemplo temos os valores `1`, `0.5`e `0.2` entrando no modelo.

- Camada Oculta (Hidden) - nesta camada encontramos os neurônios organizados em nós, interconectados com as camadas de Input e Output, que aplicam os pesos e bias aos valores recebidos. De forma didática para nosso entendimento podemos ver que estes nós neuronais estão verticalmente empilhados no número de `4` bolinhas azuis.

  > ***_NOTA :clipboard: :pencil2: :_***  é nesta camada que todo o processamento e entendimento da rede é feito. 

  O primeiro nó neuronal recebeu o valor dos Inputs, alterando-os para o resultado `0.42` e o entregará para a camada de Output.

- Camada de saída (Output) - sendo a última camada na rede, recebe o total da camada oculta.

  No nosso exemplo, o valor de Output modificado é de `0.74`.

### Olha só que interessante! :boom:

Um modelo de rede neural que não necessariamente está dentro do D.L., mas sim no M.L. 

Quando vemos um modelo de rede neural com apenas <b>uma única camada oculta</b> estamos olhando para um modelo tradicional de M.L. que sempre foi usado em diversos exemplos.

A mágica fica maior, complexa e interessante quando adicionamos <b>mais camadas ocultas</b> a este modelo que gera uma <b>Rede Neural Profunda</b>

![Aula01_Figura15](imagens/Aula01_Figura15.png)

Logo, a quantidade de camadas ocultas é o que define se meu modelo se trata de uma rede neural profunda ou apenas uma rede neural normal.

![Aula01_Figura16](imagens/Aula01_Figura16.png)

## Conectando tudo

<30:31>





## ❗️ Links & Referências usadas nesta aula

Esta aula no <a href="https://miro.com/app/board/o9J_ljr0G-g=/" target="_blank">Miro</a>

Site <a href="https://playground.tensorflow.org/" target="_blank">Tensorflow Playground</a>

Site <a href="https://www.3blue1brown.com/topics/neural-networks" target="_blank">3Blue1Brown</a>
