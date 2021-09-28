#include <stdio.h>
#include <stdlib.h>

typedef struct person_s{
    int parentGroup, groupSize;
}person_t;

int findParent(person_t *list, int number){// find parent set (search)
    return list[number].parentGroup == number ? number : (list[number].parentGroup = findParent(list, list[number].parentGroup));
}

int main(){
    int n; // n people
    scanf("%d", &n);
    person_t list[n];

    for(int i = 0; i < n; i++){// initial list
        list[i].parentGroup = i;
        list[i].groupSize = 1;
    }

    int m;
    scanf("%d", &m);
    while(m--){// set
        int person1, person2;
        scanf("%d%d", &person1, &person2);

        person1 = findParent(list, person1);
        person2 = findParent(list, person2);
        if(person1 != person2){
            if(list[person1].groupSize > list[person2].groupSize){// merge set
                list[person2].parentGroup = person1;
                list[person1].groupSize += list[person2].groupSize;
            }
            else {
                list[person1].parentGroup = person2;
                list[person2].groupSize += list[person1].groupSize;
            }
        }
    }
    printf("%d\n", list[findParent(list, 0)].groupSize);
}
