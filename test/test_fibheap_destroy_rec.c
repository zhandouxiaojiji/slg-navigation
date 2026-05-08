#include <assert.h>
#include <stdlib.h>

#include "../fibheap.h"

static int compare(struct node_data *old, struct node_data *new)
{
    if (new->f_value < old->f_value) {
        return 1;
    }
    return -1;
}

static struct node_data *new_node(int pos, int f_value)
{
    struct node_data *node = malloc(sizeof(*node));
    assert(node != NULL);
    node->pos = pos;
    node->g_value = f_value;
    node->f_value = f_value;
    node->dir = 0;
    return node;
}

int main(void)
{
    struct heap *heap = fibheap_init(128, compare);
    for (int i = 0; i < 64; i++) {
        fibheap_insert(heap, new_node(i, 64 - i));
    }
    for (int i = 0; i < 8; i++) {
        struct node_data *node = fibheap_pop(heap);
        assert(node != NULL);
        free(node);
    }
    fibheap_destroy(heap);
    return 0;
}
