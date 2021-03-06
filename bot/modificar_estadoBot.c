/// @file modificar_estadoBot.c
/// @brief As funções do bot são as mesmas do que estão documentadas nas camadas do projeto.

#include "modificar_estadoBot.h"

void atualizar_tab(ESTADO *e, COORDENADA c){
    (*e).tab[(*e).ultima_jogada.linha][(*e).ultima_jogada.coluna] = PRETA;
    (*e).tab[c.linha][c.coluna] = BRANCA;
}
void atualizar_ultima_jogada(ESTADO *e, COORDENADA c){
    (*e).ultima_jogada = c;
}
void atualizar_num_jogadas(ESTADO *e){
    if ((*e).jogador_atual == 2) (*e).num_jogadas = (*e).num_jogadas +1;
}
void atualizar_jogadas (ESTADO *e, COORDENADA c){
    if ((*e).jogador_atual == 1) (*e).jogadas[(*e).num_jogadas].jogador1 = c;
    else (*e).jogadas[(*e).num_jogadas].jogador2 = c;
}
void atualizar_jogador_atual(ESTADO *e){
    if ((*e).jogador_atual == 1) (*e).jogador_atual = 2;
    else (*e).jogador_atual = 1;
}

void armazenar_casa(ESTADO *e, int row, int col, const char casa){
    e->tab[row][col] = casa;
}

void armazenar_jogada(ESTADO *e, JOGADA jog, int num_jog){
    (*e).jogadas[num_jog] = jog;
}

void armazenar_jogador(ESTADO *e, int num_jogadas){
    if(num_jogadas % 2 == 0) (*e).jogador_atual = 1;
    else (*e).jogador_atual = 2;
}

void colocar_branca(ESTADO *e, COORDENADA c){
    (*e).tab[c.linha][c.coluna] = BRANCA;
}

void novo_num_jogadas(ESTADO *e, int num){
    (*e).num_jogadas = num/2;
}

void branca_para_vazia(ESTADO *e){
    COORDENADA c = e->ultima_jogada;
    if(c.linha == 7 && c.coluna == 7) e->tab[c.linha][c.coluna] = DOIS;
    else if(c.linha == 0 && c.coluna == 0) e->tab[c.linha][c.coluna] = UM;
    else e->tab[c.linha][c.coluna] = VAZIO;
}

void nova_ultjogada(ESTADO *e){
    int num = e->num_jogadas - 1;
    if(e->jogador_atual == 2 && num == -1){
        e->ultima_jogada.linha = 4;
        e->ultima_jogada.coluna = 4;
    }
    else if(e->jogador_atual == 1) e->ultima_jogada = e->jogadas[num].jogador1;
    else e->ultima_jogada = e->jogadas[num].jogador2;
}

void modificar_numjogadas(ESTADO *e){
    if(e->jogador_atual == 1) e->num_jogadas--;
}