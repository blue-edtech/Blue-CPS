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

No processo de M.L., os dados entram pela camada de **entrada**, e a extração deles é feita completamente por um Ser Humano. Estruturados e organizados, estes dados são classificados por uma máquina, gerando um resultado na camada de **saída**.

> ***_NOTA :clipboard: :pencil2: :_***  O processo de extração se caracteriza por observar, analisar e estruturar o conjunto de dados recebidos na camada **de entrada**.

> ***_NOTA :clipboard: :pencil2: :_***  O processo de classificação é feito inteiramente por uma máquina, através de uma ou um conjunto de fórmulas matemáticas classificando todas as features extraídas.

No processo de D.L., os dados entram pela camada de **entrada**, e os processos de extração e classificação das features, são feitos inteiramente pela máquina gerando a **saída**. A grande vantagem é que ele pode nos trazer informações interessantes e/ou relevantes, que poderiam passar despercebidas pelo Ser Humano.

> **_Obs.:_** Para ambos os processos, os dados precisam ser preparados por um Ser Humano para entrar no processo de aprendizagem.

Para que estes conceitos fiquem mais claros, assista aos vídeos a seguir:

- Este carro autônomo usa o D.L. para saber se objetos que passam no campo de visão são carros ou não: <a href="https://www.youtube.com/watch?v=mUV5ZwIC9_g&feature=youtu.be" target="_blank">Carro Autônomo</a>.

- No reconhecimento de voz as palavras são identificadas através da inserção de vários arquivos de voz: <a href="https://www.youtube.com/watch?v=NaqZkV_fBIM&feature=youtu.be" target="_blank">Reconhecimento de Voz</a>.

- Projeto GauGAN da Nvidia que transforma desenhos em paisagens usando Redes Neurais: <a href="https://www.youtube.com/watch?v=p5U4NgVGAwg" target="_blank">GauGAN</a>.

- Poder de análise de dados entre CPU vs. GPU: <a href="https://www.youtube.com/watch?v=-P28LKWTzrI" target="_blank">CPU vs. GPU</a>.

### Formas de Análise de Inserção de Dados

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

O dígito pode ter sido escrito à mão, digitado em um computador ou extraído de uma imagem. Como algoritmos, precisamos ler estes **dados inseridos** para saber que o dígito é um `5` e não uma representação dele.

Este mesmo processo de `Inserção de Dados -> Análise dos dados -> Saída` é feito pelo nosso cérebro o tempo todo. Através da rede neural, espalhada por todo o corpo é captamos as informações do ambiente, as transformamos em estímulos sensoriais que são entendidos e traduzidos pelos neurônios no cérebro que  nos devolve a informação em forma de sensação de tato, audição, visão ou paladar e a partir disso tomamos alguma decisão.

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

Vamos trabalhar novamente o exemplo da letra `A`: a informação entrará na camada Roxa de entrada, será processada na camada Laranja, e sairá pela camada Verde de saída nos trazendo o resultado se a letra `A` foi ou não identificada.

> ***Importante :bangbang: :*** Neste momento precisamos ter muito claro que a camada de entrada é por onde entram as informações e a camada de saída é por onde elas saem.

### Processamento das informações

Dentre todos os conceitos de uma rede neural, certamente o entendimento sobre <b>pesos (Wheights)</b> e <b>valores propagados (Bias)</b> são os de fundamental importância.

Quando a informação é transmitida da camada de entrada para a de processamento, os pesos são aplicados à esta informação, somados e carreados adiante para uma função de ativação juntamente com os valores de Bias.

> ***_NOTA :clipboard: :pencil2: :_***  Os pesos são coeficientes da equação que estamos tentando resolver naquele momento.

> ***_NOTA :clipboard: :pencil2: :_***  Os valores de Bias consistem em vetores adicionados ao produtos adicionados na camada de imput e dos pesos que compensam os resultados colocando-os mais ou menos para o positivo ou negativo.

Cada informação que entra pela camada de entrada é <b>multiplicada</b> por um <b>peso</b> que recebe um valor aleatório.  

![Aula01_Figura08](imagens/Aula01_Figura08.png)

Por exemplo, vamos imaginar que recebemos as letras `A` com o valor de `2` e `B` com o valor de `5` pela camada de entrada. 

O `peso A` recebe o valor de `3` e `peso B` recebe o valor de `6`.

:key: :bulb: O <b>somatório</b> será o total de: <b>(`A` * Peso A) + (`B` * Peso B) = 36 </b>.

Agora podemos adicionar um valor de bias que pode ser um número positivo ou negativo, no caso `-2`

:key: :bulb: O <b>total</b> do processamento será: <b>(somatório + bias) = 34</b>.

Com o resultado total em mãos ele será passado por uma função de ativação e a partir dela teremos um novo número que será passado para a camada de saída.

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

Para uma análise em que a camada de entrada receba um arquivo de áudio, a análise será realizada da mesma forma observando a frequência e sua intensidade.

![Aula01_Figura13](imagens/Aula01_Figura13.png)

Cada frequência carrega consigo uma intensidade, gerando uma saída que pode ser uma letra qualquer ou uma frase, por exemplo.

## Modelo de Rede Neural

<27:47>

Semelhante à representação do neurônio, o modelo de rede neural carrega a mesma estrutura.

![Aula01_Figura14](imagens/Aula01_Figura14.png)

- Camada de entrada (Input) - é a primeira camada da rede neural que recebe os valores de entrada e os passa para a próxima cada sem aplicar pesos ou bias. 

  No nosso exemplo temos os valores `1`, `0.5`e `0.2` entrando no modelo.

- Camada Oculta (Hidden) - nesta camada encontramos os neurônios organizados em nós, interconectados com as camadas de entrada e saída, que aplicam os pesos e bias aos valores recebidos. De forma didática para nosso entendimento podemos ver que estes nós neuronais estão verticalmente empilhados no número de `4` bolinhas azuis.

  > ***_NOTA :clipboard: :pencil2: :_***  é nesta camada que todo o processamento e entendimento da rede é feito. 

  O primeiro nó neuronal recebeu os valores da camada de entrada, alterando-os para o resultado `0.42` e o entregará para a camada de saída.

- Camada de saída (Output) - sendo a última camada na rede, recebe o total da camada oculta.

  No nosso exemplo, o valor de saída modificado é de `0.74`.

### Olha só que interessante! :boom:

Um modelo de rede neural que não necessariamente está dentro do D.L., mas sim no M.L. 

Quando vemos um modelo de rede neural com apenas <b>uma única camada oculta</b> estamos olhando para um modelo tradicional de M.L. que sempre foi usado em diversos exemplos.

A mágica fica maior, complexa e interessante quando adicionamos <b>mais camadas ocultas</b> a este modelo que gera uma <b>Rede Neural Profunda</b>

![Aula01_Figura15](imagens/Aula01_Figura15.png)

Logo, a quantidade de camadas ocultas é o que define se meu modelo se trata de uma rede neural profunda ou apenas uma rede neural normal.

![Aula01_Figura16](imagens/Aula01_Figura16.png)

## Conectando tudo

<30:31>

Você se lembra que falamos sobre o MINIST alguns passos atrás? 

![Aula01_Figura09](imagens/Aula01_Figura09.png)

O banco de dados do MINIST possui um conjunto de treinamento de 60.000 imagens e um conjunto de testes com 10.000, ou seja, um sub-conjunto de um conjunto maior de treinamento disponível. 

Nós utilizamos o sub-conjunto de 10.000 imagens-teste para comparar o resultado que vamos obtendo durante o treinamento e refinando o algoritmo.

Primeiro apresentamos a imagem ao modelo, o treino, ensino e comparo ao que ele não conhece para validar o resultado.

Podemos fazer uma analogia ao treino de caligrafia (pessoa idosa aqui :older_woman:) que fazíamos na escola. Até alcançarmos algo parecido com a letra da professora (é a meta que a gente almeja, né?! kkkrying) treinamos diversas vezes e ao longo do processo observamos em nosso caderno centenas de formas diferentes de fazer a mesma letra (todas um horror até a perfeição, a gente sabe! :sweat:).

Na atividade treina-compara-testa nossa rede é capaz de generalizar e abstrair e observar novas imagens nunca vistas os resultados se tornam cada vez mais positivos.

Na prática, a imagem que a rede recebe do MINIST está em em preto e branco, normalizada por tamanho e centralizada para caber em uma caixa delimitadora de pixels de 28x28, totalizando 784px, e suavização de borda criando os tons de cinza que vimos anteriormente.

Dentro do dataset estas imagens ficam dentro da categoria <b>Images</b> e ao lado encontramos as etiquetas <b>(Labels)</b> destas imagens que traz a respectiva representação para realizar a comparação.

![Aula01_Figura17](imagens/Aula01_Figura17.png)

Após escolhermos a imagem de treino para o nosso modelo precisamos realizar um procedimento antes de a colocarmos na camada de entrada, este processo se chama <b>achatamento</b>.

Este processo consiste em transformar todo o vetor de 28x28px em um vetor linear unidimensional, ou seja, de uma única linha para conectá-lo com a próxima camada.

![Aula01_Figura18](imagens/Aula01_Figura18.png)

As linhas achatadas são feitas de forma sequencial respeitando a ordem das linhas na matriz, ou seja, a primeira linha com 28 colunas é achatada e colocada na primeira posição, a segunda tem suas 28 colunas achatas e colocadas na segunda posição, e assim por diante, gerando uma única linha com 784 pixels.

Cada um destes pixels é o que de fato a rede vai usar para definir a representação da imagem.

Cada pixel da imagem contendo um valor que vai `0` a `1` equivale a um neurônio na camada de entrada.

![Aula01_Figura19](imagens/Aula01_Figura19.png)

Podemos ver que o primeiro pixel vai para o primeiro neurônio da camada e o último para seu neurônio respectivo. Desta forma temos todos os pixels da matriz representados dentro do modelo.

No nosso modelo temos 2 camadas ocultas com 16 neurônios cada.

> ***_NOTA :clipboard: :pencil2: :_***  A quantidade de camadas ocultas e seus pontos são definidos por nós

![Aula01_Figura20](imagens/Aula01_Figura20.png)

## Camada de Saída (Output)

Tudo que foi processado e se tornou relevante pelo nosso modelo deve ser apresentado nesta camada.

![Aula01_Figura21](imagens/Aula01_Figura21.png)

Em um outro exemplo, a nossa imagem de entrada é a representação do número `7`. Ela foi achatada e processada pelo modelo enchendo o neurônio do número `7` na camada de saída.

Se observarmos a figura acima atentamente perceberemos que temos um neurônio para cada número escrito à mão contido dentro do Dataset.

> ***Importante*** :bangbang: : Identificar o dígito de qualquer uma destas imagens pelo nosso Deep Learning é uma tarefa análoga a um 'Hello World!'. Atente-se à maldição. Cada possibilidade na camada de saída deve ser igualmente proporcional à quantidade de itens que serão inseridos através de representações em nosso modelo.

Quando juntamos todas as camadas de nosso modelo percebemos que a entrada e saída estão sempre conectadas e relacionadas pelo conjunto de dados.



![Aula01_Figura22](imagens/Aula01_Figura22.png)

Para sabermos se nossa rede acertou o número que inserimos, precisamos identificar o número que ela assumiu para cada uma das informações e a partir disso vemos se acertou mais ou menos.

Os dados na camada de saída são fundamentais para sabermos se a rede está acertando ou errando durante o treinamento. Lembrando que quanto mais próximo de `1` o valor dentro do neurônio chega, mais acertado é o resultado.

![Aula01_Figura23](imagens/Aula01_Figura23.png)

## Parâmetros Utilizados - Pesos e Bias

<39:24>

Cada um dos 16 neurônios da camada escondida está conectado a um pixel recebido da camada de entrada, ou seja, cada neurônio recebe os 784 pixels.

![Aula01_Figura24](imagens/Aula01_Figura24.png)

Cada peso multiplicado ao valor de entrada + bias representa a força da conexão entre os neurônios. Se o peso do neurônio `1` ao `3` for maior que o peso do neurônio `4` ao `7`, terá maior influência sobre estes.

Por lógica, percebemos que os parâmetros podem diminuir a <b>importância</b> dos pixels recebidos na camada de entrada e que serão entregues na camada de saída, dependendo de sua configuração na camada oculta.

![Aula01_Figura25](imagens/Aula01_Figura25.png)

Vamos agora a um exemplo prático e simples - e que vai quebrar a tradição do 'Hello World', certamente seremos perdoados pelos fins didáticos!

Neste exemplo temos um único pixel com <b>duas</b> possibilidade de cores.

A <b>primeira</b> possibilidade representa o pixel de cor <b>preta</b>.

A <b>segunda</b> possibilidade representa o pixel de cor <b>branca</b>.

Note que a camada de entrada tem um único ponto e a de saída dois pontos correspondentes ao preto e branco.

![Aula01_Figura26](imagens/Aula01_Figura26.png)

Quanto mais próximo de `1`, mais o neurônio de cor preta foi ativado na camada de saída.

Quanto mais próximo de `1`, mais o neurônio de cor branca foi ativado na camada de saída.

Sim! Existe a possibilidade dos neurônios serem ativados juntos. :O

Recebemos então, uma imagem com um pixel preto que foi inserida em nosso modelo e os parâmetros foram adicionados.

Cada um destes parâmetros de entrada estão conectados aos neurônios na camada oculta e a esta conexão damos o nome de <b>peso</b>.

> Para lembrar: Para cada um dos neurônios nós multiplicamos o peso ao parâmetro. 

> Para lembrar: Os pesos podem ser positivos ou negativos, dando mais ou menos força ao neurônio.

A camada oculta vai tentar entender a informação recebida em diversos níveis, a depender do que configuramos. 

Para o nosso exemplo, um pouco de branco e um pouco de preto, um neurônio para identificar a cor  branca `0` e outro neurônio para a cor preta `1`. Juntos, estes neurônios ativam simultaneamente os neurônios da camada de saída nos trazendo o resultado.

Cada um dos neurônios da camada oculta também se conectam aos da camada de saída através dos pesos.

## Combinação de Imagens para Formar um Dígito

<46:10>

Voltando ao exemplo do MINIST vamos analisar as imagens abaixo:

![Aula01_Figura27](imagens/Aula01_Figura27.png)

Perceba que a imagem do número `9` pode ser dividida em dois fragmentos, no primeiro temos um círculo, e mo segundo um traço na vertical.

Um neurônio é responsável por identificar o `primeiro fragmento` e outro neurônio o `segundo fragmento`.

Juntos, ativam o neurônio do `número 9` na camada de saída. 

![Aula01_Figura28](imagens/Aula01_Figura28.png)

Para a imagem do número `8` temos novamente dois fragmentos, um círculo maior na porção superior e um outro círculo menor na porção inferior.

> ***_NOTA :clipboard: :pencil2: :_***  As informações são quebradas desta forma por uma questão de utilidade

![Aula01_Figura29](imagens/Aula01_Figura29.png)

Na imagem do número `4`, o `primeiro fragmento` é representado por uma linha vertical que ocupa quase que totalmente a linha média do quadrado - o mesmo visto no número `9`, o `segundo fragmento` é também uma linha vertical ocupando parte do quadrante superior direito e o `terceiro fragmento` representado por uma linha na horizontal ocupando o centro do quadrado.

O treinamento de reconhecimento destas imagens são feitos ao mesmo tempo nas camadas ocultas de mais alto nível.

![Aula01_Figura30](imagens/Aula01_Figura30.png)

Assim, obteremos o seguinte resultado:

![Aula01_Figura31](imagens/Aula01_Figura31.png)

Cada um dos neurônios guarda a informação da representação de cada um dos desenhos que vimos.

A ativação dos neurônios em verde nos mostra que há grandes chances do número `4` ser ativado e os em roxo, o número `8`.

> :key: :bulb: Até aqui entendemos que a rede neural coleta as informações que está observando, as combina e toma alguma decisão a partir disso.

## Como cada pedaço de fragmento é identificado?

<49:40>

## ❗️ Links & Referências usadas nesta aula

Esta aula no <a href="https://miro.com/app/board/o9J_ljr0G-g=/" target="_blank">Miro</a>

Site <a href="https://playground.tensorflow.org/" target="_blank">Tensorflow Playground</a>

Site <a href="https://www.3blue1brown.com/topics/neural-networks" target="_blank">3Blue1Brown</a>



## Pendências

<<CHANELY - CRIAR UM DICIONÁRIO-RÁPIDO PARA OS TERMOS: (SALVATORE VALIDAR)

NEURONIO

CONEXÕES

BIAS

FUNÇÃO DE ATIVAÇÃO

CAMADA DE ENTRADA

CAMADA OCULTA

CAMADA DE SAÍDA

FORMATO DE ENTRADA

PESOS

PROPAGAÇÃO

BACKPROPAGATION

TAXA DE APRENDIZAGEM

PRECISÃO

ACURÁCIA

SENSIBILIDADE

CONVERGENCIA

REGULARIZAÇÃO

NORMALIZAÇÃO

CAMADAS COMPLETAMENTE CONECTADAS

PERDA DE FUNÇÃO

OTIMIZAÇÃO DE MODELOS

METRICAS DE PERFORMANCE

BATCH SIZE

TRAINING EPOCHS>>
