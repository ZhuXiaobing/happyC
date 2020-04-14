//
// Created by 86187 on 2020/2/1.
//

#ifndef PRACTICES_MOVIES_H
#define PRACTICES_MOVIES_H

typedef struct Movie {
    char * title;
    double rating;
} NodeData;

typedef struct MovieNode {
    NodeData node;
    struct MovieNode * next;
} NodeItem;

typedef NodeItem * Movies;

enum bool {true, false};

void InitMovieList(Movies);

enum bool MovieListIsEmpty(const Movies);

enum bool MovieListIsFull(const Movies);

void AddItemToMovieList(NodeItem item, Movies *);

void ShowMovieList(Movies, void (*func)(NodeItem * movieList));

void FreeMovieList(Movies);

#endif //PRACTICES_MOVIES_H
