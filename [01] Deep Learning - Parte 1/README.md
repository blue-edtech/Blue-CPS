# Aula #1 - Deep Learning - Parte 1

Por <a href="https://www.youtube.com/paulosalvatore" target="__blank">Paulo Salvatore</a> - Head de Produtos <a href="https://blueedtech.com.br/quem-somos/" target="__blank">@ Blue Edtech</a>

​	Olá :wave:, seja bem-vindo(a) ao nosso primeiro vídeo desta série. Nosso objetivo é introduzir o conceito de rede neural, neurônios, aprendizagem profunda, funções de ativação, algoritmo de Backpropagation e aplicação prática com TensorFlow Playground.



## Introdução

​	Antes de mergulharmos no <b>Deep Learning</b> (D.L. - aprendizagem profunda) é necessário sabermos que ele está dentro de uma estrutura de conhecimentos da <b>Inteligência Artificial</b> (I.A.).

![Aula01_Figura01](C:\Users\Chanely\Documents\Blue_CPS\Aula01_Figura01.png)

​	A I.A. começou sua evolução pela década de 50 e faz parte do campo de estudos da Ciência da Computação que se combina a conjuntos de dados robustos para permitir a resolução de problemas. Alan Turing, muitas vezes chamado de "pai da ciência da computação", frequentemente questionava se as máquinas seriam capazes de pensar. A partir daí definiu que a I.A. seria categorizada como <a href="https://www.ibm.com/br-pt/cloud/learn/what-is-artificial-intelligence" target="__blank">"sistemas que agem como humanos"</a>.

​	O <b>Machine Learning</b> (M.L. - aprendizagem de máquina) veio um pouquinho depois, se tornando uma técnica de aprendizagem de máquina para que ela reconheça padrões e aprenda em cima de um grande conjunto de dados e a partir deste aprendizado tomamos decisões, fazemos previsões, entre outros.

O Deep Learning fez sua primeira aparição entre as décadas de 70 e 80 e começou a se popularizar a partir de 2010. É um método que incorpora redes neurais em camadas para que a aprendizagem a partir dos dados seja feita de forma iterativa.

![Aula01_Figura02](C:\Users\Chanely\Documents\Blue_CPS\Aula01_Figura02.png)

​	Tanto M.L. quanto o D.L recebem informações na camada de Input e baseados nestas informações tomam decisões ou fazem alguma previsão na camada de Output, comparando aos dados que já eram conhecidos.

​	No processo de M.L. os dados entram pela camada de Input e a extração deles é feita completamente por um Ser Humano. Estruturados e organizados, estes dados são classificados por uma máquina gerando um resultado na camada de Output.

​	**_NOTA:_** O processo de extração se caracteriza por observar, analisar e estruturar o conjunto de dados recebidos na camada Input.

​	**_NOTA:_** O processo de classificação é feito inteiramente por uma máquina através de uma ou um conjunto de fórmulas matemáticas classificando todas as features extraídas.

​	No processo de D.L. os dados entram pela camada de Input e os processos de extração e classificação das features são feitos inteiramente pela máquina gerando o Output. A grande vantagem é que ele pode nos trazer informações interessantes e/ou relevantes que poderiam passar despercebidas pelo Ser Humano.

​	**_Obs.:_** Para ambos os processos, os dados precisam ser preparados por um Ser Humano para entrar no processo de aprendizagem.

​	**_Interessante:_** O D.L. é o método mais utilizado para realizar classificação de dados.

​	Para que estes conceitos fiquem mais claros assista aos vídeos abaixo:

​		- Este carro autônomo usa o D.L. para saber se objetos que passam no campo de visão são carros ou não: <a href="https://www.youtube.com/watch?v=mUV5ZwIC9_g&feature=youtu.be" target="__blank">Carro Autônomo</a>.

​		- No reconhecimento de voz as palavras são identificadas através do Input de vários arquivos de voz: <a href="https://www.youtube.com/watch?v=NaqZkV_fBIM&feature=youtu.be" target="__blank">Reconhecimento de Voz</a>.

​	- Projeto GauGAN da Nvidia que transforma desenhos em paisagens usando Redes Neurais: <a href="https://www.youtube.com/watch?v=p5U4NgVGAwg" target="__blank">GauGAN</a>.

​	- Poder de análise de dados entre CPU vs. GPU: <a href="https://www.youtube.com/watch?v=-P28LKWTzrI" target="__blank">CPU vs. GPU</a>.



### Formas de Análise de Input de Dados

​	Neste exemplo, somos um algoritmo de I.A. com o objetivo de entender informações:

![Aula01_Figura03](C:\Users\Chanely\Documents\Blue_CPS\Aula01_Figura03.png)



​	A letra "A" pode ser entendida ao analisar sua imagem com fontes diferentes ou ouvindo-a sendo dita para que ao final do processo tenhamos a letra propriamente dita e não como ela deveria ser. 

​	O mesmo processo é feito para dígitos:

![Aula01_Figura04](C:\Users\Chanely\Documents\Blue_CPS\Aula01_Figura04.png)

​	O dígito pode ter sido escrito à mão, digitado em um computador ou extraído de uma imagem. Como algoritmos precisamos ler estes Inputs para saber que o dígito é um "5" e não uma representação dele.

​	Este mesmo processo de Input -> Análise dos dados -> Output é feito pelo nosso cérebro o tempo todo. Através da rede neuronal espalhada por todo o corpo é captamos as informações do ambiente, as transformamos em estímulos sensoriais que são entendidos e traduzidos pelos neurônios no cérebro que  nos devolve a informação em forma de sensação de tato, audição, visão ou paladar e a partir disso tomamos alguma decisão.



## Preparação da Rede Neural

<13:08>



## ❗️ Links & Referências usadas nesta aula

Esta aula no [Miro][https://miro.com/app/board/o9J_ljr0G-g=/]

Site [Tensorflow Playground][https://playground.tensorflow.org/#activation=tanh&batchSize=10&dataset=circle®Dataset=reg-plane&learningRate=0.03®ularizationRate=0&noise=0&networkShape=4,2&seed=0.66474&showTestData=false&discretize=false&percTrainData=50&x=true&y=true&xTimesY=false&xSquared=false&ySquared=false&cosX=false&sinX=false&cosY=false&sinY=false&collectStats=false&problem=classification&initZero=false&hideText=false]

Site [3Blue1Brown][https://www.3blue1brown.com/topics/neural-networks]







