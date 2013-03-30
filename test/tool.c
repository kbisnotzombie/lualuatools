#include <stdio.h>
#include <sys/time.h>

/* lua */
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>

#define CLOCKS_PER_SECCOND 1000000L
#define GETCLOCKS(result) \
do{\
struct timeval __timer__;\
gettimeofday(&__timer__, NULL);\
result=(double)__timer__.tv_sec*(double)CLOCKS_PER_SECCOND+(double)__timer__.tv_usec;\
}while(0);

static double getClock(lua_State *L)
{
    double curTimestamp;
    GETCLOCKS(curTimestamp);
    return curTimestamp;
}

static const luaL_Reg tool_lib[] = {
    {"getClock", getClock},
    {NULL, NULL}
};

int luaopen_tool(lua_State *L) 
{
    luaL_register(L, "tool", tool_lib);
    return 1; 
}

