# T2 - LAB 2 - CONTROLE DE CAMPEONATO DE FUTEBOL COM LISTAS #

Todas as funcionalidades pedidas foram implementadas, com diversas listas duplamente encadeadas:
- Cadastro de times, treinadores, jogadores, rodadas e partidas;
- Exclusão de times, treinadores, jogadores, rodadas e partidas;
- Busca de times, treinadores, jogadores, rodadas e partidas;
- Impressão de times, treinadores, jogadores, rodadas e partidas;
- Montar escalação de uma partida;
- Narrar acontecimentos da partida: gols, cartões, faltas, substituições e outros lances;
- Gerar classificação geral ordenada decrescente dos times, seguindo critérios: pontos > vitórias > saldo de gols > gols pró, contemplando campos de pontuação, partidas jogadas, vitórias, empates, derrotas, gols pró, gols contra e saldo de gols;
- Gerar classificação geral ordenada decrescente de artilharia, de acordo com o número de gols de cada jogador;
- Gerar relatório de estatíticas para time ou jogador, contemplando campos de gols feitos, gols sofridos, cartões amarelos, cartões vermelhos e faltas cometidas.

Arquivos:
- listasDuplamenteEncadeadas.c e .h - funções básicas de operações com listas duplamente encadeadas;
- principal.c - demais funções adequadas para o contexto do programa para controle de um campeonato de futebol.

Structs:
- Jogador: gols feitos, gols sofridos (para goleiros), cartões, faltas, nome, posição, idade e número da camisa;
- Treinador: nome, idade e número de registro;
- Time: nome, estádio, cidade, pontos, vitórias, empates, derrotas, gols pró, gols contra, saldo de gols, treinador e lista de jogadores;
- Lance: minuto e descrição;
- Partida: id, time da casa, time visitante, gols, listas de escalação casa/fora e lista de lances;
- Rodada: número e lista de partidas.
