# Aula #5 - Back-end NodeJS - Parte 2

Por <a href="https://www.linkedin.com/in/thicode/" target="_blank">Thiago Lima</a> - Professor <a href="https://blueedtech.com.br/quem-somos/" target="_blank">@Blue Edtech</a> & <a href="https://www.linkedin.com/in/chanelym/" target="_blank">Chanely Marques</a> - Eterna Aprendiz <a href="https://blueedtech.com.br/quem-somos/" target="_blank">@Blue Edtech</a>

Olá :wave:, seja bem-vindo(a) ao quinto vídeo desta série. Nosso objetivo é introduzir conceitos básicos de construção de uma API utilizando o Node.js, Express e MongoDB. #partiu :blue_heart:

## Versionamento de Código com Git e GitHub

Para prosseguirmos em nosso tema, é necessário que você faça uma pausa aqui para assistir às aulas abaixo:

- <a href="https://www.youtube.com/watch?v=HIqyLRKv-YE" target="_blank">Como trabalhar com Git e GitHub no VsCode | Tutorial</a>
- <a href="https://youtu.be/0hJzCkqtnXQ" target="_blank">Git e GitHub: A forma mais fácil de começar a utilizar em seus projetos</a>

Seguimos... :blue_heart:

<!-- 12:00 -->

## Primeiros Passos com MongoDB

Vamos então, relembrar alguns conceitos que vimos na aula passada:

- **MongoDB** é um <a href="https://www.mongodb.com/pt-br" target="_blank">banco de dados</a> não-relacional (**NoSQL**) orientado a documentos;
- Quando nos utilizamos do termo "SQL" nos referimos à linguagem e **NoSQL** fala sobre uma base que não é somente SQL. Caso queira saber mais sobre isso, leita <a href="https://blog.geekhunter.com.br/sql-nosql-newsql-qual-banco-de-dados-usar/" target="_blank">este texto</a>.

Atualmente existem algumas formas de executar o MongoDB:

- Na máquina local, ou;
- Utilizando o <a href="https://www.mongodb.com/pt-br/cloud/atlas/register" target="_blank">MongoDB Atlas</a> que é um serviço de banco de dados na nuvem.

Pela facilidade e comodidade de acesso em qualquer lugar, **registre-se** no site do _MongoDB Atlas_ para iniciarmos os trabalhos desta aula. :wink:

Na Tela Inicial, clique em **Novo Projeto**:

![Aula05_Figura01](imagens/Aula05_Figura01.png)

Escolha um nome para o seu projeto e clique em **Next**:

![Aula05_Figura02](imagens/Aula05_Figura02.png)

Na próxima tela existe a possibilidade de adicionar novos membros ao projeto via e-mail, caso deseje. Feito isto, clique em **Create Project**:

![Aula05_Figura03](imagens/Aula05_Figura03.png)

Com o projeto criado, precisamos construir um Banco de Dados associado a ele. Clique em **Build a Database**:

![Aula05_Figura04](imagens/Aula05_Figura04.png)

Escolha a opção gratuita, selecionando **Shared**:

![Aula05_Figura05](imagens/Aula05_Figura05.png)

Na tela para seleção do _provider_, escolha a **Google Cloud** e clique em **Create Cluster**:

![Aula05_Figura06](imagens/Aula05_Figura06.png)

Para este projeto, escolhemos a Google pois seu servidor se encontra no Brasil, ajudando a diminuir os problemas de latência.

Enquanto aguarda a criação do banco, adicione um usuário e senha para o mesmo:

![Aula05_Figura07](imagens/Aula05_Figura07.png)

Criado o usuário e finalizada a criação do banco, clique em **Network Access** no menu lateral para configurar os lugares de onde nosso Banco de Dados aceitará conexões, pois na criação deixamos habilitado somente acesso local.

Clique em **_Add IP Address_**:

![Aula05_Figura08](imagens/Aula05_Figura08.png)

Selecione a opção que dá acesso de qualquer lugar e clique em **Confirm**:

![Aula05_Figura09](imagens/Aula05_Figura09.png)

> ***_Importante :mega: :_*** Apenas por questões pedagógicas estamos criando essa liberação vinda de qualquer lugar. Por questões e recomendações de segurança é necessária a liberação por IP.

Aguarde até que o _status_ mude de _Pending_ para **_Active_**:

![Aula05_Figura10](imagens/Aula05_Figura10.png)

> ***_Importante :mega: :_*** Todas as alterações que fazemos no site do _MongoDB Atlas_ chegam no e-mail. :wink:

Clicando em **_Database_** no menu lateral, podemos ver que o _Cluster_ foi criado com sucesso e disponibilizado:

![Aula05_Figura11](imagens/Aula05_Figura11.png)

Agora podemos voltar ao código para dar início às configurações. :stuck_out_tongue_winking_eye:

<!-- 19:40 -->

## Conectado a API ao Banco de Dados

Existem diversas formas de conectar uma API a um banco de dados e para auxiliar nesta tarefa, tem se tornado crescente o uso de uma _Object-Relational Mapping_ **_(ORM)_**, em tradução livre: mapeamento objeto-relacional.

A _ORM_ se trata de uma técnica que se utiliza de Orientação a Objetos para fazer dois sistemas se comunicarem. Neste caso, precisamos fazer com que o _JavaScript_ se comunique de maneira adequada com o _MongoDB_.

Através da _ORM_ conseguiremos manipular e persistir dados no banco sem necessariamente conhecer os **comandos** do _MongoDB_.

>  ***_Importante :mega: :_*** Como sempre, recomendamos a leitura da documentação do _Mongoose_, basta clicar <a href="https://mongoosejs.com/docs/index.html" target="_blank">aqui</a>.

Antes de irmos para o código, voltemos ao site do _MongoDB Atlas_ para pegarmos nossas credenciais. Clique em **_Connect_**:

![Aula05_Figura13](imagens/Aula05_Figura13.png)

Selecione a opção **_Connect your application_**:

![Aula05_Figura14](imagens/Aula05_Figura14.png)

E copie a _URL_ exibida na caixa de diálogo:

![Aula05_Figura15](imagens/Aula05_Figura15.png)

Na própria documentação eles nos informam como deve ser feita a instalação no _Noje.js_:

```bash
npm install mongoose --save
```

![Aula05_Figura12](imagens/Aula05_Figura12.png)

Instalada, vamos configurar o arquivo `index.js` para realizar a conexão com o banco:

```javascript
const express = require('express');
const app = express();
const mongoose = require('mongoose');

mongoose.connect('mongodb+srv://root:admin@cluster0.cjdgb.mongodb.net/myFirstDatabase?retryWrites=true&w=majority')

```

Onde:

- Chamamos o _Mongoose_ através de `const mongoose = require('mongoose');`, e;

- Realizamos a sua configuração através da função `mongoose.connect()` colocando entre **aspas** aquela _URL_ inteira que copiamos no passo anterior.

  **Lembre-se de substituir o campo <password> na _URL_ copiada pela senha que configurou para seu banco de dados.**

A função `mongoose.connect()`ainda recebe um segundo parâmetro que é um objeto:

```javascript
mongoose.connect(
  "mongodb+srv://root:admin@cluster0.cjdgb.mongodb.net/myFirstDatabase?retryWrites=true&w=majority", // Segundo parâmetro após esta vírgula
  {
    useNewUrlParser: true,
    useUnifiedTopology: true,
  }
);
```

Onde:

- `useNewUrlParser: true` evita que o _Mongoose_ tenha problemas com a _URL_ de conexão, e;
- `useUnifiedTopology: true` faz com que o _Mongoose_ lide com o monitoramento e reconexão do _cluster_ de forma mais eficiente.

Feito isso, precisamos configurar uma mensagem nos sinalizando de que a conexão foi fechada. Para isso, vamos nos utilizar do `try{ }`:

```javascript
try {
  mongoose.connect(
    "mongodb+srv://root:admin@cluster0.cjdgb.mongodb.net/myFirstDatabase?retryWrites=true&w=majority",
    {
      useNewUrlParser: true,
      useUnifiedTopology: true
    }
  );
  console.log('Database successfully connected!');
} catch (err) {
  console.log(`Connection failed with error: ${err}`);
}
```

Ao final, as primeiras linhas do seu `index.js`deve estar assim:

```javascript
const express = require("express");
const app = express();
const mongoose = require("mongoose");

try {
  mongoose.connect(
    'mongodb+srv://root:admin@cluster0.cjdgb.mongodb.net/myFirstDatabase?retryWrites=true&w=majority',
    {
      useNewUrlParser: true,
      useUnifiedTopology: true
    }
  );
  console.log('Database successfully connected!');
} catch (err) {
  console.log(`Connection failed with error: ${err}`);
}

app.use(express.json());
```

Vamos testar:

![Aula05_Figura16](imagens/Aula05_Figura16.png)

Perfeito! Tudo conectando certinho. :wink:

Quando falamos de bancos de dados _NoSQL_ também estamos falando de uma estrutura **Orientada a Documentos**, ou seja, este tipo de banco tem como característica conter todas as informações em um único documento.

Até aqui, a gente já viu o formato de arquivo _JSON_, que é a sintaxe utilizada pelo _MongoDB_ e que retém os dados utilizando pares de **chave/valor**.

Cada personagem que criarmos no banco possuirá quatro atributos/chaves:

- name;
- specie;
- house, e;
- portrayedBy.

Cada uma destas chaves possuirá seu respectivo valor.

Em _MongoDB_, cada conjunto de pares de chave/valor formam um **documento**.

Um conjunto de documentos dá origem a uma **coleção**.

Um conjunto de coleções, forma o **banco de dados**.

Para que possamos manipular nossos documentos utilizando o _mongoose_ precisamos definir um esquema, ou seja, a estrutura de chave/valor.

Esta estrutura não pode ficar dentro do `index.js` por se tratar de algo muito específico em relação ao banco de dados. Para resolver esta questão, vamos criar uma pasta chamada **_models_** e dentro dela o arquivo **_character.js_**

![Aula05_Figura17](imagens/Aula05_Figura17.png)

E iniciar sua configuração, chamando o _mongoose_ e criando um novo esquema:

```javascript
const mongoose =  require('mongoose');

const characterSchema = new mongoose.Schema({ });
```

Como estamos usando a mesma estrutura de um _JSON_, não podemos esquecer das **{ }** para criar o esquema. :wink:

```javascript
  name: {
    type: String,
    require: true,
  },
  specie: {
    type: String,
    require: true,
  },
  house: {
    type: String,
    require: true,
  },
  portrayedBy: {
    type: String,
    require: true,
  },
```

Dentro das chaves, inserimos o nome das nossas chaves: name, specie, house e portrayedBy.

Cada uma dessas chaves possui:

- **type**, dizendo quando o tipo de dado será inserido naquele campo, e;
- **require**, dizendo que é obrigatório o preenchimento daquele campo na requisição.

Para que a configuração deste modelo fique disponível em todo o nosso projeto, precisamos exportá-la:

```javascript
module.exports = mongoose.model('Character', characterSchema);
```

Onde:

- `module.exports` é uma das funções em _JavaScript_ para exportação;
- `mongoose.model` é uma função para exportar o módulo que criamos e demos à ela apelido de **Character** para ficar mais fácil de chamá-la, ao invés de todo o seu nome `characterSchema`.

Ao final, seu arquivo `character.js` deverá estar assim:

```javascript
const mongoose = require('mongoose');

const characterSchema = new mongoose.Schema({
  name: {
    type: String,
    require: true,
  },
  specie: {
    type: String,
    require: true,
  },
  house: {
    type: String,
    require: true,
  },
  portrayedBy: {
    type: String,
    require: true,
  },
});

module.exports = mongoose.model('Character', characterSchema);

```

Agora, vamos importar estas configurações no `index.js`:

```javascript
const Character = require("./models/character");
```

Ao final, o começo do seu `index.js` deverá estar assim:

```javascript
const express = require("express");
const app = express();
const mongoose = require("mongoose");
const Character = require("./models/character");
```

<!-- 34:00 -->

Como estamos utilizando um banco de dados, podemos agora remover a nossa lista de personagens do `index.js`:

```javascript
// Array contendo os personagens

const characters = [
  {
    id: 1,
    name: "Harry Potter",
    specie: "Human",
    house: "Gryffindor",
    portrayedBy: "Daniel Radcliffe",
  },
  {
    id: 2,
    name: "Hermione Granger",
    specie: "Human",
    house: "Gryffindor",
    portrayedBy: "Emma Watson",
  },
];

```

E dar início à configuração dos nosso **_endpoints_**, nossas rotas. Começaremos pelo _POST_:

```javascript
const { name, specie, house, portrayedBy } = req.body;
```

Como fizemos anteriormente, começamos por desestruturar os dados que chegam na requisição e validamos se cada um  deles está realmente preenchido:

```javascript
if (!name || !specie || !house || !portrayedBy) {
    res.status(400).send({ message: 'All fields must be filled'});
    return;
}
```

Ou seja, nenhum campo deve estar vazio e caso esteja, esta é a mensagem que devolvemos.

Feita a checagem, podes realizar a criação deste novo personagem no banco:

````javascript
const character = new Character({
    name, 
    specie, 
    house, 
    portrayedBy,
});
````

Para que possamos criar um novo personagem em nosso documento, estamos utilizando a função `new Character()` que é executada em um módulo separado do `index.js`.

Essa execução não é feita de forma procedural, ou seja, linha por linha, pois quando chega nesta parte do código, a criação do personagem acontece fora dele e precisamos esperar sua finalização para dar continuidade no `index.js`.

Para isto, o _JavaScript_ se utiliza de uma operação chamada **_Promise_**, onde aquele pedaço de código é executado de forma assíncrona, gerando um resultado que é processado, e a sequência do código no arquivo de origem pode continuar após a sua finalização.

Todas as vezes que vamos criar um novo personagem, o código no `index.js` precisa parar, esperar a execução do `character.js` e retornar. Para isso, damos o nome de **função assíncrona**.

>  ***_Importante :mega: :_*** _Promise_ é um conceito essencial em _JavaScript_. Você pode ler mais sobre isso clicando <a href="https://developer.mozilla.org/pt-BR/docs/Web/JavaScript/Reference/Global_Objects/Promise" target="_blank">aqui</a>.

Dizer ao código para esperar a conclusão de uma função assíncrona, utilizamos as palavras-chave **async/await**.

A `app.post()` passa a se tornar uma função assíncrona onde esperará a execução de `new Character()` para finalizar:

```javascript
// 2 - Método HTTP POST - Operação Create

app.post('/create', async (req, res) => { // Criando a função assíncrona
  const { name, specie, house, portrayedBy } = req.body;

  if (!name || !specie || !house || !portrayedBy) {
    res.status(400).send({ message: 'All fields must be filled'});
    return;
  }

  const character = await new Character({ // Esperando a execução
    name, 
    specie, 
    house, 
    portrayedBy,
  });

  res.send({ message: 'Character successfully created!' });
});

```

Após a _promise_ de criação do personagem, precisamos de uma segunda, para salvar as informações no banco:

```javasc
await character.save();
```

Ao final, seu método _POST_ deverá estar assim:

```javascript
// 2 - Método HTTP POST - Operação Create

app.post('/create', async (req, res) => {
  const { name, specie, house, portrayedBy } = req.body;

  if (!name || !specie || !house || !portrayedBy) {
    res.status(400).send({ message: 'All fields must be filled'});
    return;
  }

  const character = await new Character({
    name, 
    specie, 
    house, 
    portrayedBy,
  });

  await character.save();

  res.send({ message: 'Character successfully created!' });
});

```

Com a função concluída, podemos já executar um teste no _Thunder_:

![Aula05_Figura18](imagens/Aula05_Figura18.png)

Feita a requisição, podemos checar a criação do dado no próprio _MongoDB Atlas_, clicando em **_Browse Collections_**:

![Aula05_Figura19](imagens/Aula05_Figura19.png)

Onde vemos que nossa coleção **_characters_** possui um **documento** com os dados que acabamos de criar:

![Aula05_Figura20](imagens/Aula05_Figura20.png)

Agora que temos nosso _endpoint_ para o _POST_ funcionando, precisamos configurar o _GET_ para retornar as informações que estão salvas no banco.

<!-- 47:40 -->

Novamente, no `index.js`:

```javascript
// 1 - Método HTTP GET - Operação Read

app.get('/', async (req, res) => {
  const characters = await Character.find();
```

Configuramos nossa chamada assíncrona e armazenamos a resposta na variável `characters`. 

```javascript
  if(characters.length === 0){
    return res.status(404).send({message: 'No Character was found here!'})
  }
```

Adicionando neste método _GET_ uma verificação que nos diz se nenhum personagem foi encontrado no banco.

Ao final, seu método deverá estar assim:

```javascript
// 1 - Método HTTP GET - Operação Read

app.get('/', async (req, res) => {
  const characters = await Character.find();

  if(characters.length === 0){
    return res.status(404).send({message: 'No Character was found here!'})
  }

  res.send(characters.filter(Boolean));
});
```

E, ao realizarmos o teste pelo Thunder:

![Aula05_Figura21](imagens/Aula05_Figura21.png)

Perfeito, os dados estão sendo retornados do banco e não teremos mais problemas em perder os dados ao parar nosso terminal, caso necessário.

Vamos agora realizar a mesma mudança para nosso _GET by ID_:

```javascript
// 1.1 - Método HTTP GET - Operação Read or ID

app.get('/character/:id', async (req, res) => {
  const { id } = req.params;

  if(!mongoose.Types.ObjectId.isValid(id)){
    res.status(400).send({message: 'ID not valid!'})
  }
```

Armazenamos numa variável o _id_ recebido na _URI_ e verificamos se ele existe, e caso não exista, devolvemos uma mensagem dizendo que este _id_ é inválido.

```javascript
const character = await Character.findById(id);

if(!character){
    return res.status(404).send({message: 'Character not found!'})
}

res.send(character);
```

Na variável de personagem armazenamos a busca realizada pela função `findById()` do próprio _mongoose_ para devolver o resultado ao final.

Entretanto, antes da devolução, fazemos uma checagem para saber se aquele personagem existe ou não no banco.

Ao final, seu método deverá estar como segue>

```javascript
// 1.1 - Método HTTP GET - Operação Read or ID

app.get('/character/:id', async (req, res) => {
  const { id } = req.params;

  if(!mongoose.Types.ObjectId.isValid(id)){
    res.status(400).send({message: 'ID not valid!'})
  }

  const character = await Character.findById(id);

  if(!character){
    return res.status(404).send({message: 'Character not found!'})
  }

  res.send(character);
});
```

Ao realizar um teste busca por um _id_ inexistente, o _Thunder_ nos retorna:

![Aula05_Figura22](imagens/Aula05_Figura22.png)

Vamos testar com o _id_ `621f53fcbfc9ac1c393ce859`que é válido:

![Aula05_Figura23](imagens/Aula05_Figura23.png)

> **_NOTA:_** Ao realizar seu teste, substitua pelo _id_ que foi retornado ao utilizar o método _GET_ anteriormente.

Agora que sabemos como encontrar nosso personagem, vamos configurar nosso método _PUT_ para realizar modificações:

```javascript
// 3 - Método HTTP PUT - Operação Update

app.put('/character/:id', async (req, res) => {
  const { id } = req.params;

  if(!mongoose.Types.ObjectId.isValid(id)){
    res.status(400).send({message: 'ID not valid!'})
  }

  const character = await Character.findById(id);

  if(!character){
    return res.status(404).send({message: 'Character not found!'})
  }
```

Primeiro, procuramos se o _id_ buscado existe e é válido.

```javascript
const { name, specie, house, portrayedBy } = req.body;

if (!name || !specie || !house || !portrayedBy) {
    res.status(400).send({ message: 'All fields must be filled'});
    return;
}
```

Desestruturamos o que chega na requisição, aplicando a mesma verificação que fizemos no _POST_.

```javascript
character.name = name;
character.specie = specie;
character.house = house;
character.portrayedBy = portrayedBy;

await character.save();

res.status(200).send({message: `Character sucessfully updated: ${character}`});
```

E, por fim, enviamos as modificações para o banco, a salvamos e as devolvemos na tela. 

Ao final, seu método deverá estar assim:

```javascript
// 3 - Método HTTP PUT - Operação Update

app.put('/character/:id', async (req, res) => {
  const { id } = req.params;

  if(!mongoose.Types.ObjectId.isValid(id)){
    res.status(400).send({message: 'ID not valid!'})
  }

  const character = await Character.findById(id);

  if(!character){
    return res.status(404).send({message: 'Character not found!'})
  }

  const { name, specie, house, portrayedBy } = req.body;

  if (!name || !specie || !house || !portrayedBy) {
    res.status(400).send({ message: 'All fields must be filled'});
    return;
  }

  character.name = name;
  character.specie = specie;
  character.house = house;
  character.portrayedBy = portrayedBy;

  await character.save();

  res.status(200).send({message: `Character sucessfully updated: ${character}`});
});
```

Vamos testar:

![Aula05_Figura24](imagens/Aula05_Figura24.png)

<!-- 01:04:40 -->

Por fim, precisamos configurar o método _DELETE_.

```javascript
// 4 - Método HTTP DELETE - Operação Delete

app.delete('/character/:id', async (req, res) => {
  const { id } = req.params;

  if(!mongoose.Types.ObjectId.isValid(id)){
    res.status(400).send({message: 'ID not valid!'})
  }

  const character = await Character.findById(id);
    
  if(!character){
    return res.status(404).send({message: 'Character not found!'});
  }

  await character.remove();

  res.status(200).send({ message: 'Character sucessfully removed!' });
});
```

Fizemos a validação do _id_ que chega na requisição, buscando-o no banco se for válido e removendo-o, por fim.

![Aula05_Figura25](imagens/Aula05_Figura25.png)

Vamos realizar um _GET_ para validar:

![Aula05_Figura26](imagens/Aula05_Figura26.png)

Legal, nenhum personagem foi encontrado! :stuck_out_tongue_winking_eye:

<!-- 01:12:40 -->

Se você chegou até aqui e tudo está funcionando, adicione, remova e altere mais personagens. E não esqueça de fazer o _commit_ de suas alterações para o _GItHub_. :wink:
