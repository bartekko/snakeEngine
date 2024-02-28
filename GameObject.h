
typedef struct
{
    void (*updateFunction)(GameObject);
    void (*renderFunction)(GameObject);
    void* objData;
} GameObject;

bool GameObject_isValid();