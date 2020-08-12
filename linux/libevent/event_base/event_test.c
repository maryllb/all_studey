#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <event2/event.h>
int main()
{
    struct event_base *base;
    //创建一个base对象
    base = event_base_new();
    
    //向base中安插 监听事件
    
    //获取当前系统所支持的多路io机制
    int i;
    const char **methods = event_get_supported_methods();
    printf("Starting Libevent %s. Available methods are:\n", event_get_version());
    for (i=0; methods[i] != NULL; ++i){
        printf(" %s\n", methods[i]);
    }

    //监听 bse 上绑定的事件，满足返回相应的回调函数
    event_base_dispatch(base);      //自带循环机制 while(1){}
    
    //释放base对象
    event_base_free(base);
    printf("Hello world\n");
    return 0;
}

