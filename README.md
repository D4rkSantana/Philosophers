# Philosophers

Esse projeto se baseia na simulação do famoso problema "O jantar dos filosofos" proposto por Edsger W. Dijkstra em 1965.
Nessa simulação cada filosofo é uma thread e cada garfo um mutex, e nosso trabalho é observar em tempo real o status de cada filosofo, mostrar suas ações, monitorar uma possivel morte e tudo isso sem leaks de memoria, data racing ou deadlocks.

## Como usar?
- Clone este repositório:
``` git clone https://github.com/D4rkSantana/Philosophers.git ```
- Faça a compilação
``` make cclean ```
- execute o programa com os argumentos desejados
```./philo 4 410 200 200 7 ```

## Argumentos

- 1º Numero de filósofos
- 2º Tempo que um filosofo aguenta ficar sem comer (Em milissegundos)
- 3º Tempo que um filósofos demora para comer (Em milissegundos)
- 4º Tempo que um filósofos demora para dormir (Em milissegundos)
- 5º Numero de vezes que os filósofos devem comer para a simulação parar **\*Opcional\***

## Exemplo de de execução
- entrada:
```
	./philo 4 410 200 200 2 
```

- saida:
``` 
	2 Philosopher 3 has taken a fork
	2 Philosopher 3 has taken a fork
	2 Philosopher 3 is eating
	3 Philosopher 2 has taken a fork
	102 Philosopher 3 is sleeping
	102 Philosopher 2 has taken a fork
	102 Philosopher 2 is eating
	102 Philosopher 1 has taken a fork
	202 Philosopher 3 is thinking
	202 Philosopher 2 is sleeping
	202 Philosopher 1 has taken a fork
	202 Philosopher 1 is eating
	302 Philosopher 2 is thinking
	302 Philosopher 1 is sleeping
	302 Philosopher 3 has taken a fork
	302 Philosopher 3 has taken a fork
	302 Philosopher 3 is eating
	303 Philosopher 2 has taken a fork
	402 Philosopher 1 is thinking
	402 Philosopher 2 has taken a fork
	402 Philosopher 2 is eating
	403 Philosopher 1 has taken a fork
	502 Philosopher 1 has taken a fork
	502 Philosopher 1 is eating
 ```
