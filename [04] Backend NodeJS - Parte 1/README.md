# Aula #4 - Backend NodeJS - Parte 1

Por <a href="https://www.linkedin.com/in/thicode/" target="_blank">Thiago Lima</a> - Professor <a href="https://blueedtech.com.br/quem-somos/" target="_blank">@Blue Edtech</a> & <a href="https://www.linkedin.com/in/chanelym/" target="_blank">Chanely Marques</a> - Eterna Aprendiz <a href="https://blueedtech.com.br/quem-somos/" target="_blank">@Blue Edtech</a>

Olá :wave:, seja bem-vindo(a) ao quarto vídeo desta série. Nosso objetivo é introduzir conceitos básicos de construção de uma API utilizando o Node.js, Express e MongoDB. #partiu :blue_heart:

## Introdução

Em Tecnologia, diariamente nos deparamos com novos termos e siglas - ~~e que quase sempre deixa a gente bem lost (risos)~~. 

A sopa de letrinhas é gigantesca, nos forçando o estudo constante e perseverante. Por isso, é sempre bom nos atentarmos às definições, traduções e conceitos.

Hoje, o nosso tema é **API**, um acrônimo em inglês para (_Application Programming Interface_), em tradução livre: **interface de programação de aplicação**.

Uma API permite que sua solução ou serviço se comunique com outros produtos e serviços sem precisar saber como eles foram implementados.

> **_NOTA:_** Quando construímos uma API estamos disponibilizando um serviço que pode ser utilizado por qualquer outro serviço e/ou aplicação de maneira isolada.

> **_Curiosidade:_** Quando você ouvir/ler o termo "Consumir uma API", significa que algum serviço ou outra API está utilizando ao menos uma das funcionalidades que a API-fonte fornece.

De maneira bem simplista, podemos dividir alguns softwares em duas camadas:

- **_Frontend_**: a tela com tudo bonitinho que vemos, e;
- **_Backend_**: o lugar onde fica a lógica e também como acontece a comunicação com os dados.

Quando falamos da construção e uma API, estamos dizendo sobre uma importante parte de todo o _Backend_.

## Como funciona uma API? Onde vive? Do que se alimenta?

Até aqui, podemos concluir que parte do cérebro da nossa aplicação reside na API.

Uma API permite aos desenvolvedores de software tornem processos repetitivos, porém complexos, altamente reutilizáveis, acelerando toda o processo de entregar valor aos clientes.

Podemos ilustrar que uma API é um **grande mensageiro**...

Imagine que você está no seu restaurante favorito, com sua pessoa mais amada <3 escolhendo dentre as diversas opções no menu.

Neste cenário hipotético temos o garçom à sua espera com os pedidos e a cozinha pronta para prover a sua necessidade.

Quando o pedido é feito, o _chef_ não é capaz de recebê-lo, pois ele está focado em preparar a receita. A pessoa do caixa também não pode fazê-lo, pois está responsável em receber os pagamentos.

É aqui que encontramos a necessidade do garçom, que te conecta à cozinha fazendo nota de seu pedido, levando ao _chef_ que irá prepará-lo e à pessoa do caixa, que efetuará a cobrança.

O processo se resume em: garçom toma nota do seu pedido, entrega à cozinha, que irá prepará-lo. Quando pronto, entrega uma resposta, ou seja, o prato pronto a você.

No mundo real, podemos pinçar um site qualquer de compras que em algum momento nos pede para preencher nosso endereço para recebermos um produto.

Os Correios possuem uma API específica que nos ajuda nesta tarefa, que **recebe** o CEP que digitamos no formulário e nos **devolve**  a resposta com as informações da rua, estado, cidade, etc., nos sobrando apenas alguns complementos a serem preenchidos.

Neste cenário:

- A API do site de compras se comunica diretamente com a API dos Correios,
- Que devolve os dados que são exibidos no formulário, e;
- Ao finalizar o preenchimento e apertando o botão de "Ok", os dados são enviados e salvos no banco de dados.

> **_Importante:_** Utilizamos o termo "Persistência de Dados" para nos referir ao armazenamento de dados pelo nosso sistema após o término do processo com o qual foram criados.

Importante salientar que a API dos Correios se comunica com seu próprio banco de dados, onde os CEP's estão armazenados juntamente com as demais informações do logradouro.

## O que vamos precisa para construir nossa API?

