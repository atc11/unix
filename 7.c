#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
        mode_t oldmask,newmask;
        oldmask=umask((mode_t)0);
        printf("old mask=%o\n",(int)oldmask);
        if(oldmask & S_IRGRP)
        {
                printf("Changing the group read permission from masked to unmasked\n");
                oldmask=(oldmask ^ S_IRGRP);
        }
        newmask=(oldmask|S_IWGRP|S_IXGRP);
        umask(newmask);
        printf("Newmask=%o\n",(int)newmask);
        printf("The file mode creation mask now specifies \n");
        printf("Group read permission UNMASKED\n");
        printf("Group write permission MASKED\n");
        printf("Group execute permission MASKED\n");


        oldmask=umask((mode_t)0);
        printf("old mask=%o\n",(int)oldmask);
        if(oldmask & S_IRUSR)
        {
                printf("Changing the user read permission from masked to unmasked\n");
                oldmask=(oldmask ^ S_IRUSR);
        }
        newmask=(oldmask|S_IWUSR|S_IXUSR);
        umask(newmask);
        printf("Newmask=%o\n",(int)newmask);
        printf("The file mode creation mask now specifies \n");
        printf("User read permission UNMASKED\n");
        printf("User write permission MASKED\n");
        printf("User execute permission MASKED\n");


        oldmask=umask((mode_t)0);
        printf("old mask=%o\n",(int)oldmask);
        if(oldmask & S_IROTH)
        {
                printf("Changing the other read permission from masked to unmasked\n");
                oldmask=(oldmask ^ S_IROTH);
        }
        newmask=(oldmask|S_IWOTH|S_IXOTH);
        umask(newmask);
        printf("Newmask=%o\n",(int)newmask);
        printf("The file mode creation mask now specifies \n");
        printf("Other read permission UNMASKED\n");
        printf("Other write permission MASKED\n");
        printf("Other execute permission MASKED\n");
}
