#include "tests.h"
#include "adtmatrix.h"
#include <assert.h>

void tests() {
    ADTMatrix* mat = new ADTMatrix(10, 10);

    assert(mat->element(1, 1) == 0);
    assert(mat->element(1, 5) == 0);
    assert(mat->element(2, 7) == 0);
    assert(mat->element(10, 10) == 0);

    assert(mat->modify(1, 1, 1) == 0);
    assert(mat->modify(1, 1, 0) == 1);
    assert(mat->modify(1, 5, 3) == 0);
    assert(mat->modify(1, 5, 0) == 3);
    assert(mat->modify(10, 10, 11) == 0);
    assert(mat->modify(10, 10, 0) == 11);

    assert(mat->element(1, 5) == 0);
    assert(mat->element(10, 10) == 0);
    assert(mat->element(1, 1) == 0);
    assert(mat->element(2, 7) == 0);

    assert(mat->modify(1, 1, 1) == 0);
    assert(mat->modify(1, 5, 3) == 0);
    assert(mat->modify(10, 10, 11) == 0);

    assert(mat->element(10, 10) == 11);
    assert(mat->element(1, 1) == 1);
    assert(mat->element(1, 5) == 3);

    assert(mat->modify(1, 1, 1) == 1);
    assert(mat->modify(1, 5, 3) == 3);

    assert(mat->element(1, 1) == 1);
    assert(mat->element(1, 5) == 3);

    assert(mat->modify(1, 1, 7) == 1);
    assert(mat->modify(1, 5, 9) == 3);

    assert(mat->element(1, 1) == 7);
    assert(mat->element(1, 5) == 9);



    assert(mat->nrLines() == 10);
    assert(mat->nrCols() == 10);


}
