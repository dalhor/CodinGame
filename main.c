
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROOMS 100

typedef struct {
    int number;
    int money;
    int doors[2];
    int depth;
    int maxMoney;
} Room;

typedef struct {
    Room rooms[MAX_ROOMS];
    int numRooms;
} Building;

void readRooms(Building *building) {
    scanf("%d", &building->numRooms);
    for (int i = 0; i < building->numRooms; i++) {
        int number, money;
        char door1[2], door2[2];
        scanf("%d %d %s %s", &number, &money, door1, door2);
        building->rooms[i].number = number;
        building->rooms[i].money = money;
        building->rooms[i].doors[0] = (door1[0] == 'E') ? -1 : atoi(door1);
        building->rooms[i].doors[1] = (door2[0] == 'E') ? -1 : atoi(door2);
        building->rooms[i].depth = -1;
        building->rooms[i].maxMoney = -1;
    }
}

int calcMaxDepth(Building *building, int startRoom) {
    int maxDepth = 0;

    for (int i = 0; i < building->numRooms; i++) {
        building->rooms[i].depth = -1;
    }

    // Utiliser une pile pour parcourir les salles en profondeur
    int stack[MAX_ROOMS];
    int top = -1;
    stack[++top] = startRoom;

    while (top >= 0) {
        int currentRoom = stack[top--];
        if (building->rooms[currentRoom].depth == -1) {
            int depth1 = (building->rooms[currentRoom].doors[0] == -1) ? 0 : calcMaxDepth(building, building->rooms[currentRoom].doors[0]);
            int depth2 = (building->rooms[currentRoom].doors[1] == -1) ? 0 : calcMaxDepth(building, building->rooms[currentRoom].doors[1]);
            int maxChildDepth = (depth1 > depth2) ? depth1 : depth2;
            building->rooms[currentRoom].depth = maxChildDepth + 1;
            if (building->rooms[currentRoom].depth > maxDepth) {
                maxDepth = building->rooms[currentRoom].depth;
            }
        }
    }

    return maxDepth;
}

int calcMaxMoney(Building *building, int startRoom) {
    for (int i = 0; i < building->numRooms; i++) {
        building->rooms[i].maxMoney = -1;
    }

    // Utiliser une pile pour parcourir les salles en profondeur et calculer les gains max
    int stack[MAX_ROOMS];
    int top = -1;
    stack[++top] = startRoom;

    while (top >= 0) {
        int currentRoom = stack[top--];
        if (building->rooms[currentRoom].maxMoney == -1) {
            int money1 = (building->rooms[currentRoom].doors[0] == -1) ? 0 : calcMaxMoney(building, building->rooms[currentRoom].doors[0]);
            int money2 = (building->rooms[currentRoom].doors[1] == -1) ? 0 : calcMaxMoney(building, building->rooms[currentRoom].doors[1]);
            int maxChildMoney = (money1 > money2) ? money1 : money2;
            building->rooms[currentRoom].maxMoney = maxChildMoney + building->rooms[currentRoom].money;
        }
    }

    return building->rooms[startRoom].maxMoney;
}

int main() {
    Building building;
    building.numRooms = 0;
    readRooms(&building);

    // Calculer la profondeur maximale de chaque salle
    for (int i = 0; i < building.numRooms; i++) {
        if (building.rooms[i].depth == -1) {
            calcMaxDepth(&building, i);
        }
    }

    // Calculer le résultat maximal en parcourant les salles
    int result = calcMaxMoney(&building, 0);

    printf("%d\n", result);

    return 0;
}
