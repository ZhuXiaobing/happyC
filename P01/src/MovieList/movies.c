//
// Created by 86187 on 2020/2/1.
//

#include <stdio.h>
#include <stdlib.h>
#include "../../include/movies.h"

void InitMovieList(Movies movies) {
    movies = NULL;
}

enum bool MovieListIsEmpty(const Movies movies) {
    if (movies == NULL) {
        return true;
    } else {
        return false;
    }
}

enum bool MovieListIsFull(const Movies movies) {
    NodeItem * pt;
    enum bool full;
    pt = (NodeItem *) malloc(sizeof(NodeItem));
    if(pt == NULL){
        full = true;
    } else {
        full = false;
    }
    free(pt);
    return full;
}

void AddItemToMovieList(NodeItem item, Movies * movies) {
    NodeItem * pt;
    pt = (NodeItem *) malloc(sizeof(NodeItem));
    pt->node.title = item.node.title;
    pt->node.rating = item.node.rating;
    if (MovieListIsEmpty(*movies) == true) {
        *movies = pt;
    } else {
        Movies movieList = *movies;
        while (movieList->next != NULL) {
            movieList = movieList->next;
        }
        movieList->next = pt;
    }
}

void ShowMovieList(Movies movies, void (*func)(NodeItem * nodeItem)) {
    if (MovieListIsEmpty(movies) == true) {
        return;
    } else {
        do {
            (*func)(movies);
            movies = movies->next;
        } while (movies != NULL);
    }
}

void FreeMovieList(Movies movies) {
    while(movies != NULL) {
        NodeItem * current = movies;
        movies = movies->next;
        free(current);
    }
}