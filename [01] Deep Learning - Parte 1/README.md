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

> ***_Importante :mega: :_*** Para ambos os processos, os dados precisam ser preparados por um Ser Humano para entrar no processo de aprendizagem.

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

O dígito pode ter sido escrito à mão, digitado em um computador ou extraído de uma imagem. Como algoritmos, precisamos ler estes **dados** para saber que o dígito é um `5` e não uma representação dele.

Este mesmo processo de `Entrada de dados -> Análise -> Saída` é feito pelo nosso cérebro o tempo todo. Através da rede neural, espalhada por todo o corpo é captamos as informações do ambiente, as transformamos em estímulos sensoriais que são entendidos e traduzidos pelos neurônios no cérebro que  nos devolve a informação em forma de sensação de tato, audição, visão ou paladar e a partir disso tomamos alguma decisão.

## Preparação da Rede Neural

<!-- 13:08 -->

Para que o cérebro consiga de fazer todas as coisas que hoje sabemos que é capaz de fazer, podemos imaginar que um único neurônio têm sua estrutura e forma de funcionar bastante complexa. 

Por hora não vamos nos servir desta complexidade, mas sim de sua simplicidade funcional: receber e transmitir impulsos elétricos, ou seja, receber e transmitir informações.

![Aula01_Figura06](imagens/Aula01_Figura06.png)

A estrutura básica de um neurônio consiste em:

- **Dendritos**: é por aqui que as informações entram - `Input`,
- **Corpo celular**: recebidas as informações, as mesmas serão analisadas, processadas e decididas quanto ao destino,
- **Axônio envolto de ilhas de bainha de mielina**: fio condutor responsável por transmitir as informações do corpo celular para o axônio terminal, e;
- **Axônio terminal**:  é por aqui que as informações saem - `Output`.

Para que as informações saiam do axônio terminal `A` para o dendrito do axônio `B`, uma estrutura chamada **sinapse** — que pode ser química ou elétrica — é ativada através do estímulo que sai do axônio terminal de `A` para o dendrito de `B`.

Graças à essas sinapses, nosso cérebro é capaz de processar 11 bilhões de bits por segundo através de conexões paralelas entre todos os neurônios.

> ***_Curiosidade :brain: :_***  Uma sinapse se forma entre um neurônio do cérebro com outro neurônio do cérebro. Quando um neurônio do cérebro precisa falar com uma célula muscular para ativar qualquer músculo no corpo, a estrutura se chama **junção neuromuscular**.

Este conceito de processar informações paralelamente é bastante aplicado à computação. Chamado de **processamento paralelo**, ele explora e usa simultaneamente várias unidades de processamento (CPU's) para aumentar a velocidade.

Por exemplo, ao ouvirmos a letra `A`, a informação do som (em Hz) é transmitida pelos condutos auditivos e captada pelos neurônios especializados. Estes captadores formam uma cascata de estímulos elétricos ativando o processamento paralelo nas áreas cerebrais especializadas em audição, para que finalmente o reconhecimento da informação `A` seja feito e devolvido para nós em forma de "Hmm, isso que eu ouvi é a letra `A`, eu a conheço!".

Este mesmo processo é feito para todas as informações que captamos do ambiente através dos 5 sentidos.

> Por hora, queremos que você guarde o seguinte: podemos fazer uma analogia de tudo que vimos acima a um único neurônio de máquina. Na máquina. este neurônio realiza uma função muito simples que é a de armazenar um número que, a princípio, será entre 0 e 1.

![Aula01_Figura05](imagens/Aula01_Figura05.png)

## Representação Matemática

<!-- 16:59 -->

Vamos observar e estudar com calma a figura abaixo:

![Aula01_Figura07](imagens/Aula01_Figura07.png)

Paralelamente à estrutura funcional de um neurônio, esta representação matemática possui uma região que recebe **valores de entrada** (equivalente aos dendritos), outra que **analisa, processa e envia as informações** (equivalente ao corpo celular e axônio) e, por fim, a que faz a **saída** (equivalente ao axônio terminal).

Vamos trabalhar novamente o exemplo da letra `A`:

- a informação entrará na camada Roxa de entrada;
- será processada na camada Laranja; e
- sairá pela camada Verde de saída nos trazendo o resultado se a letra `A` foi ou não identificada.

> ***_Importante :mega: :_*** Neste momento precisamos ter muito claro que a camada de entrada é por onde entram as informações e a camada de saída é por onde elas saem.

### Processamento das informações

Dentre todos os conceitos de uma rede neural, certamente o entendimento sobre **pesos (weights)** e **valores propagados (bias)** são fundamentais (talvez a parte mais importante da uma rede neural 🙂).

Quando a informação é transmitida da camada de entrada para a de processamento, os pesos são aplicados à esta informação, somados e passados adiante para uma função de ativação, juntamente com os valores de Bias.

Cada **informação que entra** pela camada de entrada é **multiplicada** por um **peso** (que inicialmente corresponde um valor aleatório) antes de avançar pela rede neural.

![Aula01_Figura08](imagens/Aula01_Figura08.png)

Após essa múltiplicação da **informação que entra** vezes o **peso**, aplicamos em um **somatório**, que representa a soma de todos os valores.

Por exemplo, vamos imaginar que recebemos na camada de entrada as letras `A` e `B`, cada uma com o seguinte valor:

- `Letra A` = `2`
- `Letra B` = `5`

Para cada letra, recebemos também um **peso**, com os seguintes valores:

- `Peso A` = `3`
- `Peso B` = `6`

Com isso, temos os seguinte cálculo para saber o valor do **somatório**:

- `(Letra A * Peso A) + (Letra B * Peso B)`

Substituindo pelos valores:

- `(2 * 3) + (5 * 6)` que é igual a `36`

:key: :bulb: Portanto, o valor do **somatório** é `36`.

 Agora, podemos somar um valor de **bias** — que pode ser um número positivo ou negativo — e nesse caso será `-2`.

- `Somatório + Bias`
- `36 + -2` é igual a `34`

:key: :bulb: Portanto, o resultado corresponde a `34`.

Com o resultado total em mãos, ele será passado por uma função de ativação e, a partir dela, teremos um novo número que será passado para a camada de saída.

Vamos entrar mais a fundo em cada uma dessas partes?

<!-- 21:55 -->

## Dataset MNIST

Para aprofundarmos nosso estudo e deixá-lo mais tangível, vamos falar sobre um banco de dados bastante específico chamado **MNIST** que contém imagens binárias de dígitos escritos à mão por diversas pessoas.

![Aula01_Figura09](imagens/Aula01_Figura09.png)

> ***_Importante :mega: :_*** Desenvolver uma rede neural capaz de compreender os dígitos destas imagens é considerado o primeiro exemplo a ser aprendido por quem quer entender o universo, equivalente ao `Hello World!` no universo da programação. (PS: atente-se à maldição :jack_o_lantern:)

O MNIST se tornou uma estrutura bem difundida entre a comunidade Deep Learning. Diversos outros projetos seguem a mesma base de imagens em escala de cinza, de tamanho 28x28 pixels, com 60.000 arquivos para treino e 10.000 arquivos para teste, organizadas em 10 classes distintas.

No caso do MNIST, cada classe distinta representa um dos números de 0 a 9.

### Fashion MNIST

O **[Fashion MNIST](https://github.com/zalandoresearch/fashion-mnist)**, um banco de dados de imagens que segue a estrutura do MNIST, possui imagens de peças de roupa, também organizadas em 10 classes distintas.

![Aula01_Figura10](imagens/Aula01_Figura10.png)

No vídeo-exemplo abaixo, podemos analisar como um algoritmo observa um conjunto de dados com artigos de moda em geral e os posiciona por similaridade.

![Aula1_Gif01](imagens/Aula01_Gif01.gif)

## E como interpretamos as imagens?

<!-- 23:57 -->

Das 70.000 imagens que podemos encontrar no MNIST, vamos pegar uma delas para o nosso exercício. Essa imagem possui um tamanho de `28px` de largura por 28px de altura, totalizando `784px`, organizados em linhas e colunas, da seguinte forma:

![Aula01_Figura11](imagens/Aula01_Figura11.png)

Cada pixel na imagem é análogo a um neurônio, contendo números que vão do intervalo de 0 a 1.

![Aula01_Figura12](imagens/Aula01_Figura12.png)

Quanto mais próximo o neurônio estiver do número `1`, significa que ele está sendo mais ativado. Observe na imagem que a cor fica mais branca o número `1.0` dentro dele, enquanto os outros pontos estão mais claros (entre `0.01` e `0.99`) ou até mesmo completamente pretos (`0.0`).

> ***_NOTA :clipboard: :pencil2: :_***  No dataset do MNIST, todas as imagens acompanham o significado do que ela representa. No nosso exemplo, a imagem recebe o significado `3`.

## E quando não temos imagens?

Para uma análise em que a camada de entrada receba um arquivo de áudio, a análise será realizada da mesma forma observando a frequência e sua intensidade.

![Aula01_Figura13](imagens/Aula01_Figura13.png)

Cada frequência carrega consigo uma intensidade, gerando uma saída que pode ser uma letra qualquer ou uma frase, por exemplo.

## Modelo de Rede Neural

<!-- 27:47 -->

Semelhante à representação do neurônio, o modelo de rede neural carrega a mesma estrutura.

![Aula01_Figura14](imagens/Aula01_Figura14.png)

- **Camada de entrada (Input):** é a primeira camada da rede neural que recebe os valores de entrada.

  No nosso exemplo temos os valores `1`, `0.5`e `0.2` entrando no modelo.

- **Camada Oculta (Hidden):** nesta camada encontramos os neurônios organizados em nós, interconectados com as camadas de entrada e saída, que aplicam os pesos e bias aos valores recebidos. De forma didática e para nosso entendimento, podemos ver que estes nós estão verticalmente empilhados e correspondem a `4` bolinhas azuis.

  > ***_NOTA :clipboard: :pencil2: :_***  é nesta camada em que a rede realmente identifica o que está sendo recebido.

  O primeiro neurônio da camada oculta recebeu os valores da camada de entrada, aplicou os pesos e o bias, alterando-os para o resultado `0.42`, entregando esse valor para a camada de saída.

- **Camada de saída (Output):** sendo a última camada na rede, recebe o total da camada oculta.

  No nosso exemplo, o valor de saída modificado é de `0.74`.

### Olha só que interessante! :boom:

Um modelo de rede neural que não necessariamente está dentro do D.L., mas sim no M.L.

Quando vemos um modelo de rede neural com apenas **uma única camada oculta** estamos olhando para um modelo tradicional de M.L., que usamos em diversos exemplos.

A mágica fica maior, complexa e interessante quando adicionamos **mais camadas ocultas** a este modelo, caracterizando uma **Rede Neural Profunda**.

![Aula01_Figura15](imagens/Aula01_Figura15.png)

Logo, a quantidade de camadas ocultas é o que define se meu modelo se trata de uma rede neural profunda ou apenas uma rede neural normal.

![Aula01_Figura16](imagens/Aula01_Figura16.png)

## Conectando tudo

<!-- 30:31 -->

Você se lembra que falamos sobre o MNIST alguns passos atrás? 

![Aula01_Figura09](imagens/Aula01_Figura09.png)

O banco de dados do MNIST possui um conjunto de treinamento de 60.000 imagens e um conjunto de testes com 10.000, ou seja, um sub-conjunto de um conjunto maior de treinamento disponível. 

Nós utilizamos o sub-conjunto de 10.000 imagens-teste para comparar o resultado que vamos obtendo durante o treinamento e refinando o algoritmo.

Primeiro, apresentamos as imagens de **treino** ao modelo para que ela aprenda a reconhecer os padrões. Com isso, medimos os resultados.

Para garantir que os resultados são coerentes, apresentamos as imagens de **teste** e verificamos se os resultados são tão satisfatórios quanto.

> Podemos fazer uma analogia ao treino de caligrafia (pessoa idosa aqui :older_woman:) que fazíamos na escola. Até alcançarmos algo parecido com a letra da professora (é a meta que a gente almeja, né?! kkkrying) treinamos diversas vezes e, ao longo do processo, observamos em nosso caderno centenas de formas diferentes de fazer a mesma letra (todas um horror até a perfeição, a gente sabe! :sweat:).

Na atividade **treina-compara-testa**, nossa rede é capaz de generalizar, abstrair e observar novas imagens, garantindo que os resultados se tornam cada vez mais positivos (algo que pode ser medido na curva de aprendizado de uma rede neural).

Na prática, a imagem que a rede recebe do MNIST está em em preto e branco, normalizada por tamanho e centralizada para caber em uma caixa delimitadora de pixels de `28x28`, totalizando `784px`, e suavização de borda criando os tons de cinza que vimos anteriormente.

Dentro do dataset, organizamos os arquivos das imagens (`Images`) em um local e a representação das imagens (`Labels`) em outro.

![Aula01_Figura17](imagens/Aula01_Figura17.png)

Após escolhermos a imagem de treino para o nosso modelo, precisamos realizar um procedimento antes de a colocarmos na camada de entrada, este processo se chama **achatamento**.

Este processo consiste em transformar todo a matriz de `28x28px` em um vetor linear unidimensional, ou seja, em uma única linha, para conectá-lo com a próxima camada.

![Aula01_Figura18](imagens/Aula01_Figura18.png)

As linhas achatadas são feitas de forma sequencial, respeitando a ordem das linhas na matriz, ou seja, a primeira linha com 28 colunas é achatada e colocada na primeira posição, a segunda tem suas 28 colunas achatas e colocadas na segunda posição, e assim por diante, gerando uma única linha com 784 pixels.

Cada um destes pixels é o que de fato a rede vai usar para definir a representação da imagem.

Cada pixel da imagem contendo um valor que vai `0` a `1` equivale a um neurônio na camada de entrada.

![Aula01_Figura19](imagens/Aula01_Figura19.png)

Podemos ver que o primeiro pixel vai para o primeiro neurônio da camada e o último para seu neurônio respectivo. Desta forma, temos todos os pixels da matriz representados dentro do modelo.

No nosso modelo de exemplo temos 2 camadas ocultas com 16 neurônios cada.

> ***_NOTA :clipboard: :pencil2: :_***  A quantidade de camadas ocultas e de neurônios são definidas por nós e existem várias técnicas para saber quando adicionar/remover camadas e neurônios.

![Aula01_Figura20](imagens/Aula01_Figura20.png)

## Camada de Saída (Output)

Tudo que foi processado e se tornou relevante pelo nosso modelo deve ser apresentado nesta camada.

![Aula01_Figura21](imagens/Aula01_Figura21.png)

Em um outro exemplo, a nossa imagem de entrada é a representação do número `7`. Ela foi achatada e processada pelo modelo enchendo o neurônio do número `7` na camada de saída.

Se observarmos a figura acima atentamente perceberemos que temos um neurônio para cada número escrito à mão contido dentro do Dataset.

> ***_Importante :mega: :_*** Identificar o dígito de qualquer uma destas imagens pelo nosso Deep Learning é uma tarefa análoga a um 'Hello World!'. Atente-se à maldição. Cada possibilidade na camada de saída deve ser igualmente proporcional à quantidade de itens que serão inseridos através de representações em nosso modelo.

Quando juntamos todas as camadas de nosso modelo percebemos que a entrada e saída estão sempre conectadas e relacionadas pelo conjunto de dados.



![Aula01_Figura22](imagens/Aula01_Figura22.png)

Para sabermos se nossa rede acertou o número que inserimos, precisamos identificar o número que ela assumiu para cada uma das informações e, a partir disso, vemos se acertou mais ou menos.

Os dados na camada de saída são fundamentais para sabermos se a rede está acertando ou errando durante o treinamento. Lembrando que, quanto mais o valor do neurônio estiver próximo de `1`, mais certo está o resultado.

![Aula01_Figura23](imagens/Aula01_Figura23.png)

## Parâmetros Utilizados - Pesos e Bias

<!-- 39:24 -->

Cada um dos 16 neurônios da camada escondida está conectado a um pixel recebido da camada de entrada, ou seja, cada neurônio recebe os 784 pixels.

![Aula01_Figura24](imagens/Aula01_Figura24.png)

Cada **peso** multiplicado ao **valor de entrada + bias** representa a força da conexão entre os neurônios. Se o peso do neurônio `1` ao `3` for maior que o peso do neurônio `4` ao `7`, terá maior influência sobre estes.

Por lógica, percebemos que os parâmetros podem diminuir a **importância** dos pixels recebidos na camada de entrada e que serão entregues na camada de saída, dependendo de sua configuração na camada oculta.

![Aula01_Figura25](imagens/Aula01_Figura25.png)

Vamos agora a um exemplo prático e simples — e que vai quebrar a tradição do 'Hello World' (certamente seremos perdoados pelos fins didáticos!).

Neste exemplo temos um único pixel com **duas** possibilidade de cores.

A **primeira** possibilidade representa o pixel de cor **preta**.

A **segunda** possibilidade representa o pixel de cor **branca**.

Note que a **camada de entrada** tem um único ponto e a de **saída** dois pontos, correspondentes ao preto e ao branco.

![Aula01_Figura26](imagens/Aula01_Figura26.png)

Quanto mais próximo de `1`, mais o neurônio de cor preta foi ativado na camada de saída.

Quanto mais próximo de `1`, mais o neurônio de cor branca foi ativado na camada de saída.

Sim! Existe a possibilidade dos neurônios serem ativados juntos 😮!

Recebemos então, uma imagem com um pixel preto. Chamaremos esse único pixel de **um parâmetro**.

Esse **parâmetro de entrada** está conectado aos neurônios na camada oculta. A esta conexão, damos o nome de **peso**.

> ***_Para lembrar :thought_balloon: :_***Para cada um dos neurônios, multiplicamos parâmetro e peso.

> ***_Para lembrar :thought_balloon: :_***Os pesos podem ser positivos ou negativos, dando mais ou menos força àquela conexão.

A camada oculta vai tentar entender a informação recebida em diversos níveis, dependendo do que foi configurado.

Cada um dos neurônios da camada oculta também se conectam aos da camada de saída. Em cada conexão, tambem temos um novo valor de pesos, que definirá as ativações finais. Essas ativações finais representam o que de fato a rede identificou.

## Combinação de Imagens para Formar um Dígito

<!-- 46:10 -->

Voltando ao exemplo do MNIST, vamos analisar as imagens abaixo:

![Aula01_Figura27](imagens/Aula01_Figura27.png)

Perceba que a imagem do número `9` pode ser dividida em dois fragmentos, no primeiro temos um círculo, e no segundo um traço na vertical.

Um neurônio é responsável por identificar o `primeiro fragmento` e outro neurônio o `segundo fragmento`.

Juntos, ativam o neurônio do `número 9` na camada de saída. 

![Aula01_Figura28](imagens/Aula01_Figura28.png)

Para a imagem do número `8` temos novamente dois fragmentos — o mesmo círculo do `9` — na porção superior, e um outro círculo menor na porção inferior.

> ***_NOTA :clipboard: :pencil2: :_***  As informações são quebradas desta forma por uma questão de utilidade.

![Aula01_Figura29](imagens/Aula01_Figura29.png)

Na imagem do número `4`, o `primeiro fragmento` é representado por uma linha vertical — a mesmo vista no número `9` —, o `segundo fragmento` é também uma linha vertical e o `terceiro fragmento` representado por uma linha na horizontal.

O treinamento de reconhecimento destas imagens são feitos ao mesmo tempo nas camadas ocultas de mais alto nível.

> ***_NOTA :clipboard: :pencil2: :_*** As camadas ocultas de mais alto nível são aquelas que estão mais próximas da camada de saída.

![Aula01_Figura30](imagens/Aula01_Figura30.png)

Assim, obteremos o seguinte resultado:

![Aula01_Figura31](imagens/Aula01_Figura31.png)

Cada um dos neurônios guarda a informação da representação de cada um dos desenhos que vimos.

A ativação dos neurônios em verde nos mostra que há grandes chances do número `4` ser ativado. Já ativação dos neurônios em roxo, maiores chances de ser o número `8`.

> :key: :bulb: Até aqui entendemos que a rede neural coleta as informações que está observando, as combina, e toma alguma decisão a partir disso.

## Como cada pedaço de fragmento é identificado?

<!-- 49:40 -->

Em média, um Ser Humano é capaz de desenhar um círculo somente aos 3 anos de idade. Neste perído, estamos aprendendo a coordenar o campo visual juntamente com a musculatura fina da mão-de-escrita para que o formato redondo saia no papel. É uma tarefa complexa e desafiadora e o mesmo acontece no aprendizado da Rede Neural.

> **_Curiosidade :brain: :_** O círculo é um símbolo universal com significado amplo, nos remete às noções de totalidade, plenitude, perfeição original, o Eu, o infinito, a eternidade. Interessante notar que uma das formas mais espalhadas na natureza exija tanto de nós aprendermos seu formato. 

![Aula01_Figura32](imagens/Aula01_Figura32.png)

Note no exemplo abaixo, que o entendimento do que é um círculo pela Rede Neural é a junção de `5 fragmentos`.

![Aula01_Figura33](imagens/Aula01_Figura33.png)

Lembra que anteriormente mencionamos que o aprendizado de algumas imagens é feito em uma camada de alto nível?

![Aula01_Figura34](imagens/Aula01_Figura34.png)

Na primeira camada de neurônios no exemplo acima, a informação que já foi aprendida é fragmentada em pequenos pedaços e juntada com as informações da segunda camada para formar algo novo, como o formato do círculo que vimos no dígito `9`. O mesmo acontece com a sua perninha, o seu reconhecimento também é fragmentado pela Rede Neural:

![Aula01_Figura35](imagens/Aula01_Figura35.png)

Para fins didáticos podemos dividir o processo de aprendizado do dígito `9` em quatro etapas:

- Camada de Input: recebimento do dígito `9` achatado;
- Primeira camada oculta: fragmentos do dígito `9` são reconhecidos e ativados;
- Segunda camada oculta: o dígito `9` é construído com apenas dois fragmentos ativando apenas dois neurônios, e;
- Camada de saída: preenchimento do neurônio correspondente ao dígito `9`.
	

![Aula01_Figura36](imagens/Aula01_Figura36.png)

> :key: :bulb: Lembre-se que cada neurônio é um parâmetro multiplicado por peso e bias.

## Evoluindo a função do neurônio

Até aqui tratamos o neurônio como **algo que guarda um número**. Após tudo que estudamos, vimos que seu trabalho vai além disso: **o neurônio é uma função matemática**.

![Aula01_Figura37](imagens/Aula01_Figura37.png)

Por ser uma função, o neurônio agora vai **receber** números e **transformá-los** tornando todo o processo de aprendizagem mais flexível.

Vamos assimilar todas essas informações desta forma:

Recebemos o nosso neurônio inicial com seus parâmetros configurados. 

![Aula01_Figura38](imagens/Aula01_Figura38.png)

Para a nossa **primeira** camada oculta os parâmetros são a camada de entrada. 

- O **primeiro** pixel será multiplicado pelo peso aleatório `1`.

![Aula01_Figura39](imagens/Aula01_Figura39.png)

> :key: :bulb: Neste momento vamos assumir que o valor do peso é definido de forma **aleatória**.

- O **segundo** pixel será multiplicado pelo peso aleatório `2`.

![Aula01_Figura40](imagens/Aula01_Figura40.png)

Por exemplo:

- Parâmetro 1 x Peso 1: `1 x 0 = 0`
- Parâmetro 2 x Peso 2: `1 x 5 = 5`

Tendo em mãos o resultado de cada parâmetro, o resultado final será:

- `Total = 5`

![Aula01_Figura41](imagens/Aula01_Figura41.png)

> :key: :bulb: Para cada pixel entrando nós repetimos sua multiplicação pelo peso e o somamos aos que entraram na camada anteriormente

Não podemos esquecer de agregar o **valor de bias** que pode ser um valor negativo ou positivo, e que neste momento também será aleatório. 

- Parâmetros + bias: `5 + 30 = 35`

![Aula01_Figura42](imagens/Aula01_Figura42.png)

> :key: :bulb: Os valores aleatórios são ajustados conforme a Rede Neural vai crescendo em aprendizado. Os valores aleatórios são ajustados conforme a Rede Neural vai crescendo em aprendizado.

Com o valor total da soma de parâmetros + bias em mãos, precisamos passá-lo por uma **função de ativação** que o transformará em outro resultado. 

Neste momento esta função dobra o valor recebido.

- Total anterior -> função de ativação: `35 x 2 = 70`

![Aula01_Figura43](imagens/Aula01_Figura43.png)

> :key: :bulb: A forma de funcionamento da função de ativação é determinada por nós. Por exemplo: por ela só seriam transformados números pares.

O processo de **aprendizado da Rede Neural** pode ser entendido da através de todas essas etapas que passamos. 

- O neurônio é uma estrutura com uma função de ativação.
- Os pesos e bias inicialmente são valores aleatórios
- O valor de cada peso e bias é ajustado conforme o aprendizado vai aumentando.

> :key: :bulb: Em síntese, aprendizado é ajustar os pesos e bias de forma correta e adequada. :bulb: :key:

![Aula01_Figura44](imagens/Aula01_Figura44.png)

## Determinando a quantidade de pesos em uma Rede Neural Profunda

<!-- 56:35 -->

Sabemos que para cada pixel que entrando pela camada de entrada têm seu parâmetro multiplicado pelo peso e somado ao valor de bias.

Vamos usar o exemplo para uma Rede Neural que possui **16 neurônios** em ambas camadas ocultas e **784 pixels** entrando pela camada de entrada.

Cada neurônio terá seu parâmetro somado ao bias na **primeira camada oculta**.

Cada neurônio terá seu parâmetro somado ao bias na **segunda camada oculta**.

Este total será multiplicado pelas `10` opções dispostas na **camada de saída**.

![Aula01_Figura45](imagens/Aula01_Figura45.png)

> :key: :bulb: O valor total deste cálculo resulta na **quantidade de pesos** desta Rede Neural Profunda.

>  :key: :bulb: Mais ou menos pesos depende da sua estrutura de camadas internas.

## Funções em Rede Neural

<!-- 57:50 -->

Existem diversas funções à nossa disposição para trabalharmos. Vamos começar com uma bastante simples, sua notação matemática é a seguinte:

`f(x) = 2x`

Uma função é sempre algo que **transforma** um valor. Podemos imaginá-la como uma caixa onde uma informação está entrando (**Input**), passa pelo corpo da caixa, e sua transformação é devolvida na saída (**Output**).

![Aula01_Figura46](imagens/Aula01_Figura46.png)

Supondo que colocamos o valor de `10` na camada de entrada, ele é multiplicado por `2`, resultando em `20` na camada de saída.

Se assumirmos que o valor de `x` será `10`, onde `x` aparecer, seu valor será `10`.

- `f(x) = 2x`
- `f(x) = 2 x 10`
- f(x) = 20

A função `f` recebendo o valor `(10)` na entrada, terá o valor `20` na camada de saída.

Vamos supor que queremos `f(x)` para o intervalo de `-10 a 10`. Graficamente poderemos representar desta forma:

![Aula01_Figura47](imagens/Aula01_Figura47.png)

Note que o número `1` do eixo **x** assume valor `2` em **y**.

Passando o intervalo de `-10 a 10` teremos como resultado o intervalo de `-20 a 20`.

> ***_NOTA :clipboard: :pencil2: :_*** Sempre podemos colocar uma função em um gráfico para observar seu comportamento e dizer se é o que esperamos dela.

![Aula01_Figura48](imagens/Aula01_Figura48.png)

Para saber mais a respeito de funções e como funcionam, recomendamos o material do Deep Learning Book - [Capítulo 8](https://www.deeplearningbook.com.br/funcao-de-ativacao/). 

### Escolhendo a Função de Ativação Correta

<!-- Paulo, vale colar aqui no material a pincelada que você deu sobre estas funções e dar exemplos? -->

### Função Sigmoide

<!-- 1:05:11 -->

Vamos novamente recorrer ao recurso visual para nos ajudar. No exemplo abaixo, temos um intervalo de valor que vai de `-5 a 5`:

![Aula01_Figura49](imagens/Aula01_Figura49.png)

- Se o valor de **x** está entre `0 e 2` o valor de **y** estará entre `0 e 0.9`.

- Se o valor de **x** está entre `2 e 5` o valor de **y** estará entre `0.9 e 1`.

Podemos notar que quando **x** está próximo a `0` o valor de **y** é bastante influenciado e o mesmo não acontece quando **x** se afasta de `0`.

O mesmo acontecerá quando o intervalor de **x** estiver entre `0 e -2`.

> ***_NOTA :clipboard: :pencil2: :_*** A função **sigmoide** também transforma um número. Se o valor de entrada for `2`, ela devolverá `0.9` como valor de saída.

Abaixo, podemos ver a representação de um neurônio funcionando com a função sigmoide:

![Aula01_Figura50](imagens/Aula01_Figura50.png)

O valor de entrada `a1` é multiplicado pelo peso `w1` e o mesmo acontece para a quantidade de valores que entram. 

Após o resultado de todas as somas, o valor de bias é aplicado. No exemplo, `-10`.

> ***_NOTA :clipboard: :pencil2: :_*** A complexidade dos cálculos matemáticos são todos feitos pelo computador. A nós, cabe somente escolher a função que mais se adequa ao nosso propósito.

## Recapitulando

<!-- 1:07:10 a 1:16:00 - TRANSFORMAR ESTE PEDAÇO EM UM RESUMO (BULLETS) QUE ANTECEDE TUDO E COLOCAR NA TABELA DA PÁGINA INICIAL FORA DESTE MAIN MATERIAL? -->

<!-- 1:07:10 a 1:16:00 - TRANSFORMAR ESTE PEDAÇO EM UM RESUMO (BULLETS) E INSERIR NO COMEÇO DO MATERIAL DO VÍDEO 02? -->

## Entendendo o Processo de Aprendizado de Máquina

<!-- 1:16:13 -->

A essência do treinamento em Redes Neurais é o método de **backpropagation**, que realiza um ajuste fino dos pesos da Rede Neural com base na **taxa de erros** obtidos. 

![Aula01_Figura51](imagens/Aula01_Figura51.png)

Adequadamente feitos os ajustes, as taxas de erro vão diminuindo tornando o modelo confiável e aumentando sua capacidade de generalizar os resultados.

> ***_NOTA :clipboard: :pencil2: :_***  Backpropagation é o método padrão de treinamento em Redes Neurais

Quando falamos em **erros** cometidos pela Rede Neural, buscamos entender o quão longe estamos de acertar.

![Aula01_Figura52](imagens/Aula01_Figura52.png)

Vamos agora relembrar o ciclo de uma Rede Neural e para fixarmos, adicionaremos o Backpropagation.

- Elegemos uma **base de treino** para o nosso modelo e realizamos o processo de achatamento das imagens que queremos utilizar;
- As informações são inseridas na **camada de entrada**;
- Os parâmetros de **peso** são aplicados;
- Do valor obtido é então feito o **somatório**;
- O **bias** é aplicado a estes parâmetros;
- O valor resultante é passado pela **função de ativação**;
- A **previsão** extraída da função de ativação é comparada ao **resultado esperado** através de uma **função de erro**;
- A função de erro determina **a quantidade de erros**.

![Aula01_Figura53](imagens/Aula01_Figura53.png)

- Assim como acontece conosco quando analisamos nossos erros diante de um aprendizado para um desafio, o mesmo acontece no aprendizado da máquina. **Cada erro nos aproxima do resultado esperado**.
- Saber o resultado que queremos nos permite fazer um **ajuste nos pesos** e refazer o processo até chegar novamente na função de erro.

![Aula01_Figura54](imagens/Aula01_Figura54.png)

> ***_NOTA :clipboard: :pencil2: :_*** As previsões vão ficando cada vez mais assertivas conforme este ciclo vai se repetindo.

Este ciclo que se repete até a assertividade completa se chama **época**.

Para cada imagem inserida na camada de entrada, uma época é realizada. Seu número de repetições e o entendimento do que acontece individualmente em cada uma é configurado por nós. 

Graças à tecnologia, e aos que vieram antes de nós, todo o processo matemático de cada época é realizado por bibliotecas. :boom:

Você se lembra que o Dataset do MNIST possui 60.000 imagens de treino? Cada uma dessas imagens passa por uma época e paralelamente a comparação com a **base de testes** é feita para que possamos fazer os ajustes.

![Aula01_Figura55](imagens/Aula01_Figura55.png)

O processo de comparação com a base de testes é extremamente importante, não só para avaliar o que estamos fazendo mas também para nos dizer sobre um problema chamado **_Overfitting_**.

O _overfitting_ acontece quando estamos acertando muito a base de treino e errando na mesma proporção na base de testes, ou seja, quando estamos exagerando no polimento dos parâmetros.

![Aula01_Figura56](imagens/Aula01_Figura56.png)

Pode acontecer de nos preocuparmos demasiadamente em ensinar nosso algoritmo não necessariamente em generalizar e reconhecer o problema e sim ensinando a base de treino.

:key: :bulb: É igualmente importante acertar a base de treino e também a base de testes para que o algoritmo seja capaz de reconhecer no dia-a-dia imagens novas e nunca vistas.

## Entendendo a Função de Erro

<!-- 1:26:53 -->

Novamente, vamos usar uma imagem para nos ajudar a entender. 

A linha de cor `laranja` possui pontos de cor `azul` espalhados que acompanham seu traçado.

Cada ponto azul possui uma distância entre sua borda e o ponto que ele toca a reta laranja naquele momento do espaço.

![Aula01_Figura59](imagens/Aula01_Figura59.png)

Para definirmos a quantidade de erros e acertos necessitamos separar cada uma das retas e somar suas diferenças, ou seja:

- r1 = possui 2 unidades
- r2 = possui 2 unidades
- r3 = possui 1 unidade
- r4 = possui 1 unidade
- r5 = possui 1 unidade

> ***_NOTA :clipboard: :pencil2: :_*** Neste momento, o valor de cada ponto (r) não interfere no resultado pois representa apenas uma unidade.

A soma total é de `7` unidades, ou seja, o **erro total foi de 7 unidades**.

![Aula01_Figura58](imagens/Aula01_Figura58.png)

Utilizando-nos da matemática percebemos que ao percorrer a linha laranja possuímos somente **um único acerto**, pois `-2` anula `2` e `-1` anula `1`. 

![Aula01_Figura57](imagens/Aula01_Figura57.png)

O algoritmo de Rede Neural não trabalha com números negativos e por este motivo as **funções de erro geralmente consideram a soma dos erros quadrados**, ou seja, todos os valores negativos são **elevados ao quadrado**.

> ***_Importante :mega: :_*** Quanto maior a barra de erros, ou seja, mais longe de `0`, mais erros cometemos ao configurar o algoritmo. 

> ***_Importante :mega: :_***Quanto mais próximo de `0`, menos erros cometemos ao configurar o algoritmo. No nosso exemplo erramos bastante pois `7` está bastante longe de `0`.

<!-- Paulo, a ordem de apresentação dos conteúdos abaixo não ficou muito clara pra mim. Você pode por gentileza organizar? -->

No exemplo abaixo, podemos perceber como isso funciona de outra forma:

![Aula01_Figura60](imagens/Aula01_Figura60.png)

Podemos observar que a camada de saída do modelo possui diversos neurônios bastante cheios, tendo o do número `8` se destacando. Entretanto, o resultado esperado é o número `3`.

>  ***_NOTA :clipboard: :pencil2: :_*** O "custo" da diferença entre o resultado esperado e o resultado na camada de output se chamada **_Utter Trash_**.

Sugerimos que dê uma pausa aqui e assista o terceiro vídeo da 3Blue1Brown [neste link](https://www.3blue1brown.com/lessons/neural-network-analysis) para que veja o processo de _Utter Trash_ acontecendo.

Uma função de erro normalmente resulta em uma parábola, nos possibilitando encontrar o ponto mais baixo da função de erro.

![Aula01_Figura61](imagens/Aula01_Figura61.png)

Obtendo este menor valor, conseguimos minimizar a função, aproximando o valor de `0`, que é o nosso objetivo.

A parábola acima não é o que normalmente encontramos em Redes Neurais, e sim, um formato que se assemelha a **vales**. 

![Aula01_Figura62](imagens/Aula01_Figura62.png)

A bolinha acima vai caminhando pelos vales de acordo com os ajustes feitos nos pesos conforme vamos executando as épocas. A camada de saída da Rede nos mostrará se devemos ajustar o peso para **mais** ou para **menos**.

Sempre, **o vale mais adequado para o nosso objetivo é o que mais próximo está de `0`**.

> ***_Importante :mega: :_*** Encontrar o ponto ótimo, ou seja, nos aproximarmos de `0` é o processo do aprendizado da rede em si.

Sugerimos que dê uma pausa aqui e assista o segundo vídeo da 3Blue1Brown [neste link](https://www.3blue1brown.com/lessons/gradient-descent) para que este conteúdo fique mais claro em sua mente.

## TensorFlow - Nosso Lugar para Experimentar em Redes Neurais 

Ao acessar o site do [TensorFlow Playground](https://playground.tensorflow.org/) nos deparamos com uma estrutura de Rede Neural.

![Aula01_Figura63](imagens/Aula01_Figura63.png)

As **_features_** consistem nas propriedades que vamos alimentar a rede.

No exemplo acima possuímos `2` camadas escondidas, a **primeira** com `4` neurônios e a **segunda** com apenas `2`.

>  Tanto a quantidade de camadas ocultas quanto a de neurônios pode ser modificada.

No canal **_Data_** escolhemos o _dataset_ que iremos trabalhar.

No exemplo acima, podemos observar na camada de saída diversas bolinhas `azuis` ao centro cercadas de diversas bolinhas `laranjas`. Neste caso, o que a Rede precisa entender é que:

- azul representa `informação` com valor `1`, e;
- laranja representa `informação` com valor `-1`.

Quando apertamos o Play, dizemos à rede para executar as épocas e iniciar o aprendizado. Note como ela está na **época 340**.

![Aula01_Figura64](imagens/Aula01_Figura64.png)

Na camada de saída vida evidente que a Rede está se ajustando cada vez mais em diferenciar o que é bolinha azul e bolinha laranja.

Quando a base de treino atinge o valor `0.001`, neste exemplo, uma estagnação foi atingida e nenhum aprendizado está sendo somado ao processo.

> ***_Importante :mega: :_*** Se dermos o Play diversas vezes notaremos que a camada de saída apresentará um comportamento diferente por conta do refinamento no ajuste dos pesos, que de início, são aleatórios.

## Desafio Proposto

Nosso desafio para você hoje é configurar a rede para aprender o problema **espiral** que está incluso no _dataset_ do site.



Até a volta! :blue_heart:

## ❗️ Links & Referências usados nesta aula

Esta aula no <a href="https://miro.com/app/board/o9J_ljr0G-g=/" target="_blank">Miro</a>

Site <a href="https://playground.tensorflow.org/" target="_blank">Tensorflow Playground</a>

Site <a href="https://www.3blue1brown.com/topics/neural-networks" target="_blank">3Blue1Brown</a>



## Pendências

<!-- CHANELY - CRIAR UM DICIONÁRIO-RÁPIDO PARA OS TERMOS: (SALVATORE VALIDAR) -->

<!-- NEURONIO -->

<!-- CONEXÕES -->

<!-- BIAS -->

<!-- FUNÇÃO DE ATIVAÇÃO -->

<!-- CAMADA DE ENTRADA -->

<!-- CAMADA OCULTA -->

<!-- CAMADA DE SAÍDA -->

<!-- FORMATO DE ENTRADA -->

<!-- PESOS -->

<!-- PROPAGAÇÃO -->

<!-- BACKPROPAGATION -->

<!-- TAXA DE APRENDIZAGEM -->

<!-- PRECISÃO -->

<!-- ACURÁCIA -->

<!-- SENSIBILIDADE -->

<!-- CONVERGENCIA -->

<!-- REGULARIZAÇÃO -->

<!-- NORMALIZAÇÃO -->

<!-- CAMADAS COMPLETAMENTE CONECTADAS -->

<!-- PERDA DE FUNÇÃO -->

<!-- OTIMIZAÇÃO DE MODELOS -->

<!-- METRICAS DE PERFORMANCE -->

<!-- BATCH SIZE -->

<!-- TRAINING EPOCHS -->
