#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;
void custom_fs_int(int *custom_x)
{
    register int c = getchar_unlocked();
    *custom_x = 0;
    int is_neg = 0;

    for(; ((c<48 || c>57) && c != '-'); c = getchar_unlocked());

    if(c=='-')
    {
        is_neg = 1;
        c = getchar_unlocked();
    }

    for(; c>47 && c<58 ; c = getchar_unlocked())
    {
        *custom_x = (*custom_x<<1) + (*custom_x<<3) + c - 48;
    }

    if(is_neg){*custom_x = -(*custom_x);}
}

typedef struct
{
    int next_idx;
    int value;
    int distance;
} CustomList;

typedef struct
{
    int parent_node;
    int shortest_path;
    ll path_count;
    int is_on_stack;
    int children;
} CustomNode;

#define MOD_VAL 1000000007

ll compute_sum(CustomNode *tree, CustomList *list)
{
    CustomNode *current, *next;
    int i, j, count=0, limit;
    ll result = 0;
    static int *stack=NULL, stack_size=1000;

    if (!stack){stack = malloc(sizeof(int) * stack_size);}

    stack[count++] = 1;
    int current_distance;

    while(count)
    {
        limit = count;
        for (i=0; i<limit; i++)
        {
            current = &tree[stack[i]];
            stack[i--] = stack[--limit];
            stack[limit] = stack[--count];
            current->is_on_stack = 0;

            for (j=current->children; j; j=list[j].next_idx)
            {
                if (list[j].value == 1){continue;}

                next = &tree[list[j].value];
                current_distance = current->shortest_path + list[j].distance;

                if (next->shortest_path != 0 && next->shortest_path < current_distance){continue;}
                else if (next->shortest_path == current_distance){next->path_count++;}
                else if (next->shortest_path == 0 || next->shortest_path > current_distance)
                {
                    next->shortest_path = current_distance;
                    next->path_count = 1;
                    if (!next->is_on_stack)
                    {
                        if (count >= stack_size)
                        {
                            stack_size <<= 1;
                            stack = realloc(stack, sizeof(int) * stack_size);
                        }
                        stack[count++] = list[j].value;
                        next->is_on_stack = 1;
                    }
                }
            }
        }
    }

    return result;
}

void set_tree_depth(CustomNode *tree, CustomList *list, int root, int current_depth, int parent_node)
{
    int i;
    tree[root].parent_node = parent_node;
    for (i=tree[root].children; i; i=list[i].next_idx)
      {
        if (list[i].value == parent_node){continue;}
        else{set_tree_depth(tree, list, list[i].value, current_depth + 1, root);}
      }
}

int main()
{
    int test_cases, num_hotels, num_paths, i, u, v, d;
    custom_fs_int(&test_cases);
    int list_index = 1;
    CustomNode tree[100005];
    CustomList list[200005];
    CustomList *tmp_list;

    while (test_cases--)
    {
        custom_fs_int(&num_hotels);
        custom_fs_int(&num_paths);
        list_index = 1;

        memset(tree, 0, sizeof(tree));
        memset(list, 0, sizeof(list));

        for (i=0; i<num_paths; i++)
        {
            custom_fs_int(&u);
            custom_fs_int(&v);
            custom_fs_int(&d);

            tmp_list = &list[list_index];
            tmp_list->next_idx = tree[u].children;
            tmp_list->value = v;
            tmp_list->distance = d;
            tree[u].children = list_index++;

            tmp_list = &list[list_index];
            tmp_list->next_idx = tree[v].children;
            tmp_list->value = u;
            tmp_list->distance = d;
            tree[v].children = list_index++;
        }

        compute_sum(tree, list);

        ll result = 1;
        for (i=2; i<=num_hotels; i++){result = ((result % MOD_VAL) * (tree[i].path_count % MOD_VAL)) % MOD_VAL;}
        printf("%lld\n", result);
    }

    return 0;
}
//
// Created by zerri on 2/12/2025.
//