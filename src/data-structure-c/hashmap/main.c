#include "hashmap.h"

int main(void)
{
    HashMap *map = create_new(5);
    Node *node = create_new_node("a", "1");
    add(map, "a", node);
    node->value = "2";
    free(node);
    node = create_new_node("b", "2");
    add(map, "b", node);
    print_debug(map);

    return 0;
}
