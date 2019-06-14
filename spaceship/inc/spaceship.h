#define THRUST_ON  1
#define THRUST_OFF 0

typedef struct {
    /* Constant properties */
    const int32_t mass, thrust_force;

    /* State variables */
    int32_t pos_x, pos_y; // Position
    int32_t vel_x, vel_y; // Velocity
    int32_t hitpoints, ammunition;
    int8_t thrust_state;
} Spaceship;

typedef struct {
    /* Constant properties */
    const int32_t mass, radius;
    const int32_t pos_x, pos_y; // Position

    /* State variables */
    int32_t hitpoints;
    int8_t powerup;
} Asteroid;

typedef struct {
    /* Constant properties */
    const int32_t mass, damage;

    /* State variables */
    int32_t pos_x, pos_y; // Position
    int32_t vel_x, vel_y; // Velocity
} Projectile;
