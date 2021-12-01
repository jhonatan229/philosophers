# Documentação


## gettimeofday
essa função serve para poder pegar o momento em segundos e microseguntos, do horario exato em que a função foi chamada, guardando em uma struct timeval, dentro dela tem a 
tv_sec, onde guarda os segundos, e o tv_usec, onde guarda em formato de microsegundos, caso vc chame essa função mais para frente na aplicação, ela retornara outros valores 
nessa struct, valores maiore, ja que se passou um tempo a mais.
Nesse projeto, o esquema é ter duas variaveis com essa struct, chamar o gettimeofday uma vez no começo do projeto, e quando vc quiser saber o tempo passado dentro da aplicação, só chamar novamente essa função, passando a outra struct, e facer o tv_usec da segunda struct - tv_user da primeira struct, com isso vc tera o tempo passado dentro do projeto


## pthread_create
Cria uma nova thread dentro do processo atual, e vincula ele com uma função, que seria uma finção d einicialização da thread, algo que ele vai fazer quando puder  
> int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);  

thread: No caso seria a thread que vai iniciar, ele precisa ser um tipo pthread_t, e precisa mandar um ponteiro;  
attr: Não usarei esse nesse projeto;
start routine: seria uma função criada por vc onde retorna void *, e tem como unico parametro, uma variavel void *, essa variavel é a mesma colocada dentro do ultimo parametro  
arg: que no caso seria essa, ela é mandada como parametro para a start routine;

Em um mundo perfeito, essa thread rodaria o start routine no momento de ter sido criada, mas dependendo da infra da maquina, ela pode ser executada mais para frente, ou na hora de ser criada, ou nem mesmo rodar, não tem como controlar, mas para isso, tem a próxima função;

## pthread_join
Esse carinha faz com que a função passada no start routine na hora da criação da thread seja executado imediatamente, caso essa rotina ja tenha sido executada, ele apenas não fara nada  
> int pthread_join(pthread_t thread, void **retval);

thread: É a thread que vc quer que a rotina seja executada;  
retval: ela guarda o retorno da função de rotina da thread, ja que essa função retorna um void*, ela pode ser qualquer coisa;

