                #ifdef __APPLE__
                #include <GLUT/glut.h>
                #else
                #include <GL/glut.h>
                #endif
                #include <stdlib.h>
                #include<iostream>
                #include <GL/gl.h>

                #include <GL/glu.h>
                #include <GL/glut.h>
                #include<bits/stdc++.h>
                #include<iostream>
                #include <string>
                #include<windows.h>
                #include<mmsystem.h>

                using namespace std;

                 ///global variables

                int num_disks=10;
                char yo[1000];
                int t=0;
                long long inc=2;
                string s;
                string sss1="";
                string sss4="";
                string sss5="";
                string sss2="Moves:";
            const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
            const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
            const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
            const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };
            const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
            const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
            const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
            const GLfloat high_shininess[] = { 100.0f };
                clock_t start=clock();
                double duration;
                GLfloat  poleColor[] = {1.0, 0.2, 0.2, .8};
                void display();
                void specialKeys();
                double rotate_y=0;
                double rotate_x=0;
                double zoom=0.0;
                double pan_hor=0.0;
                double pan_ver=0.0;
                #define MAX 10
                ofstream solution;
                ofstream user_solution;
                int moves=0;
                int sound_is_playing=1;
                typedef struct {
                    int number;
                    float xcoord;
                    float ycoord;
                    float zcoord;
                    float radius;
                    float cx;
                    float cy;
                    float cz;
                } disks;


                std::string to_string(int i)
                {
                    std::stringstream ss;
                    ss << i;
                    return ss.str();
                }

                ///declaring class stack

                class Stack
                {
                private:
                       int arr[MAX];
                       int top;

                public:
                      Stack()
                      {
                            top = -1;
                      }

                       void Push(int item)
                      {
                             if(top == MAX-1)
                            {
                                  cout<<endl<< "Stack is full";
                                   return;
                            }

                            top++;
                            arr[top] = item;
                      }

                       int Pop()
                      {
                             if(top == -1)
                            {
                                  cout<<endl<< "Stack is empty";
                                   return NULL;
                            }

                            int data = arr[top];
                            top--;

                             return data;
                      }
                      int top_ele()
                      {
                        return arr[top];
                      }
                      int empty()
                      {
                        if(top==-1)
                        return 1;
                        else
                        return 0;
                      }
                      int noEle()
                      {
                        return top;
                      }

                };


                Stack s1,s2,s3;
                disks disk[10];

                ///functions

                void output(GLfloat x, GLfloat y, char *text) {

                    ///outputs text on screen

                char *p;  int i=0;
                  glPushMatrix();
                  glTranslatef(x, y, 0);
                for (p = text; *p; p++)
                /*
                 to display character
                */
                                  glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
                                  glPopMatrix();
                }

     ///when solution is asked by user.

                void tower(int a,char from,char aux,char to){

                    ///Base Case

                   if(a==1){

                       solution<<"\t\tMove disc 1 from "<<from<<" to "<<to<<"\n";
                int i1=1;
                                    s2.Push(1);
                            cout<<"\t\tMove disc 1 from "<<from<<" to "<<to<<"\n";
                                    if(from=='A' && to=='B')
                                    {
                                        ///rod a to b
                                        disk[i1].xcoord=0;
                                    disk[i1].ycoord=s2.noEle()+disk[num_disks-1].ycoord-0.5;

                                    }
                                    else if(from=='A' && to=='C')
                                    {
                                        ///rod a to c
                                    disk[i1].xcoord=-1;
                                    disk[i1].ycoord=s3.noEle()+disk[num_disks-1].ycoord-0.5;
                                    }
                                    else if(from=='B' && to=='A')
                                    {
    ///rod b to a
                                        disk[i1].xcoord=1;
                                    disk[i1].ycoord=s1.noEle()-0.1;
                                    }
                                    else if(from=='B' && to=='C')
                                    {
    ///rod b to c
                                        disk[i1].xcoord=-1;
                                    disk[i1].ycoord=s3.noEle()+disk[num_disks-1].ycoord-0.5;
                                    }
                                    else if(from=='C' && to=='A')
                                    {
    ///rod c to a
                                        disk[i1].xcoord=1;
                                    disk[i1].ycoord=s1.noEle()-0.1;
                                    }
                                    else if(from=='C' && to=='B')
                                    {
    ///rod c to b
                                        disk[i1].xcoord=0;
                                    disk[i1].ycoord=s2.noEle()+disk[num_disks-1].ycoord-0.5;
                                    }
                                    sound_is_playing=0;

                                    PlaySound("disk.wav", NULL, SND_ASYNC|SND_FILENAME);


                            moves++;


                       return;
                    }
                    else{
                       tower(a-1,from,to,aux);

                       solution<<"\t\tMove disc "<<a<<" from "<<from<<" to "<<to<<"\n";
                            if(to=='B'&&from=='A')
                        {
                            ///rod a to b
                            int i1=a;
                 s1.Pop();
                                    s2.Push(i1);
                            cout<<"element "<<i1<< " moved from s1 to s2 "<<endl;
                                    sss1="element "+to_string(i1)+ " moved from s1 to s2";
                                    sound_is_playing=0;

                                    PlaySound("disk.wav", NULL, SND_ASYNC|SND_FILENAME);
                                    disk[i1].xcoord=0;
                                    disk[i1].ycoord=s2.noEle()+disk[num_disks-1].ycoord-0.5;

                            moves++;
    }
                    else if(to=='C'&&from=='A')
                        {
                            int i1=a;
                           /// rod a to c
                            s1.Pop();
                                    s3.Push(i1);
    cout<<"element "<<i1<< " moved from s1 to s3 "<<endl;sss1="element "+to_string(i1)+" moved from s1 to s3 ";
                                    sound_is_playing=0;
    PlaySound("disk.wav", NULL, SND_ASYNC|SND_FILENAME);
                                    disk[i1].xcoord=-1;
                                    disk[i1].ycoord=s3.noEle()+disk[num_disks-1].ycoord-0.5;
                                    moves++;

                            }

                 else if(to=='A'&&from=='B')
                       {
                          /// rod b to a
                           int i1=a;
                           s2.Pop();
                                    s1.Push(i1);
                                    cout<<"element "<<i1<< " moved from s2 to s1 "<<endl;sss1="element "+to_string(i1)+" moved from s2 to s1 ";
                                    sound_is_playing=0;

                                    PlaySound("disk.wav", NULL, SND_ASYNC|SND_FILENAME);
                                    disk[i1].xcoord=1;
                                    disk[i1].ycoord=s1.noEle()-0.1;

                                    moves++;
    }

                       else if(to=='C'&&from=='B')
                        {
                            ///rod b to c
                            int i1=a;
                            s2.Pop();
                                    s3.Push(i1);
                                    cout<<"element "<<i1<< " moved from s2 to s3 "<<endl;sss1="element "+to_string(i1)+" moved from s2 to s3 ";
                                    sound_is_playing=0;

                                    PlaySound("disk.wav", NULL, SND_ASYNC|SND_FILENAME);
                                    disk[i1].xcoord=-1;
                                    disk[i1].ycoord=s3.noEle()+disk[num_disks-1].ycoord-0.5;

                                    moves++;
                           /// rod b to c
    }
                 else if(to=='A'&&from=='C')
                        { int i1=a;
                           /// rod c to a
                        s3.Pop();
                                    s1.Push(i1);
                                    cout<<"element "<<i1<< " moved from s3 to s1 "<<endl;sss1="element "+to_string(i1)+" moved from s3 to s1 ";
                                    sound_is_playing=0;

                                    PlaySound("disk.wav", NULL, SND_ASYNC|SND_FILENAME);
                                    disk[i1].xcoord=1;
                                    disk[i1].ycoord=s1.noEle()-0.1;
                                    moves++;
    }
                        else if(to=='B'&&from=='C')
                        {
                             int i1=a;
                            ///rod c to b
                           s3.Pop();
                                    s2.Push(i1);
                                    cout<<"element "<<i1<< " moved from s3 to s2 "<<endl;sss1="element "+to_string(i1)+" moved from s3 to s2 ";
                                    sound_is_playing=0;

                                    PlaySound("disk.wav", NULL, SND_ASYNC|SND_FILENAME);
                                    disk[i1].xcoord=0;
                                    disk[i1].ycoord=s2.noEle()+disk[num_disks-1].ycoord-0.5;
                                    moves++;
    }
                        tower(a-1,aux,from,to);
                        }
    }
    struct Points{
    float x, y;
    Points() {x = 0.0; y= 0.0;}
    Points(float _x, float _y): x(_x),y(_y){}
};
Points convert(int x, int y)
{

    return Points((((float)x/(400.0)))-1.0,((-1.0)*((float)y/(250.0)))+1.0);
}
float mx = 0.0;
float my = 0.0;
    void drag(int x, int y)
{
    float n_mx,n_my;
    Points mouse_point = convert(x, y);
    n_mx = mouse_point.x;
    n_my = mouse_point.y;
    if(n_mx-mx>0){
        rotate_y+=3;}
    if(n_mx-mx<0){
        rotate_y-=3;}
    if(n_my-my>0){
        rotate_x+=3;}
    if(n_my-my<0){
        rotate_x-=3;}
    mx = n_mx;
    my = n_my;
    glutPostRedisplay();

}

        void draw_cylinder(){

            ///making three cylinders

                    float x=(float)(num_disks+2)/10;
                    GLUquadricObj *quadratic;
                    quadratic = gluNewQuadric();

                glPushMatrix();
                        glColor3f(1,0,0);
                        glTranslatef(1,-0.1,0);
                        glRotatef(90, -1, 0, 0);
                        gluCylinder(quadratic, 0.05f, 0.05f, x, 32, 32);
                glPopMatrix();

                glPushMatrix();
                      glColor3f(1,0,0);
                      glTranslatef(0,-0.1,0);
                        glRotatef(90, -1, 0, 0);
                      gluCylinder(quadratic, 0.05f, 0.05f, x, 32, 32);
                glPopMatrix();

                glPushMatrix();
                        glColor3f(1,0,0);
                        glTranslatef(-1,-0.1,0);
                        glRotatef(90, -1, 0, 0);
                        gluCylinder(quadratic, 0.05f, 0.05f, x, 32, 32);
                glPopMatrix();
                }

                void draw_torus1(){

                    ///making of disks

                   float x=0.08,yo=0;

                   for(int i =1; i<=num_disks;i++){

                         glColor3f(disk[i].cx,disk[i].cy,disk[i].cz);
                            glPushMatrix();
                            glTranslatef(disk[i].xcoord,(-disk[num_disks-1].ycoord+disk[i].ycoord)/12,disk[i].zcoord);
                            glRotatef(90, -1, 0, 0);
                            glutSolidTorus(0.045, 0.08+x/2.5, 100, 100);
                            x=x+0.08;
                            glPopMatrix();

                    }
    }

                void draw_string()
                {

                    ///writing text on screen

                    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.0f);///needs to be called before RasterPos
    ///towers of hanoi written
                    glRasterPos2i(1, 2);

                    void * font = GLUT_BITMAP_9_BY_15;
                 s="Towers Of Hanoi";
                    for (string::iterator i = s.begin(); i != s.end(); ++i)
                    {
                        char c = *i;

                        glutBitmapCharacter(font, c);
                    }

                    glColor3f(1.0f, 0.0f, 0.0f);///needs to be called before RasterPos
                    glRasterPos2i(0, 2);
        for (string::iterator i = sss1.begin(); i != sss1.end(); ++i)
                    {
                        char c = *i;

                        glutBitmapCharacter(font, c);
                    }
                    ///number of moves displayed
                      glRasterPos2i(2, 2);

                    sss2="Moves: "+to_string(moves);
                    for (string::iterator i = sss2.begin(); i != sss2.end(); ++i)
                    {
                        char c = *i;

                        glutBitmapCharacter(font, c);
                    }
                     glRasterPos2i(2, 1.5);
                    for (string::iterator i = sss4.begin(); i != sss4.end(); ++i)
                    {
                        char c = *i;

                        glutBitmapCharacter(font, c);
                    }
        glPopMatrix();
                glEnable(GL_TEXTURE_2D);

                }

                ///display function

                void display(){

    if(s3.noEle()==num_disks-1)
                        {
                            sss4="SOLVED!!!";
                            sound_is_playing=0;
                PlaySound("Ta Da.wav", NULL, SND_ASYNC|SND_FILENAME);

                        }

                    ///  Clear screen and Z-buffer
                    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);


                    /// Reset transformations
                    glLoadIdentity();

                    gluLookAt(0.0+pan_hor,1.0+pan_ver,-3.0+zoom,0.0,0.0,0.0,0.0,1.0,0.0);

                    /// Rotate when user changes rotate_x and rotate_y
                glRotatef( rotate_x, 1.0, 0.0, 0.0 );
                glRotatef( rotate_y, 0.0, 1.0, 0.0 );
                 glColor3f(  0.5,  0.0,  0.0 );
                 draw_cylinder();
                draw_torus1();
                draw_string();

                ///timer function
          glColor3f(1.0f, 0.0f, 0.0f);
                     void * font = GLUT_BITMAP_9_BY_15;
                     glRasterPos2i(2, 1);
                duration=(clock())/CLOCKS_PER_SEC;


                sss5="Time: "+to_string(duration);

                for (string::iterator i = sss5.begin(); i != sss5.end(); ++i)
                    {
                        char c = *i;

                        glutBitmapCharacter(font, c);
                    }
                    glPopMatrix();
                    glEnable(GL_TEXTURE_2D);
                glFlush();
                glutSwapBuffers();
                }

                /// specialKeys() Callback Function

                void specialKeys( int key, int x, int y ) {

                    ///  Right arrow - increase rotation by 5 degree
                    if (key == GLUT_KEY_RIGHT)
                    rotate_y += 5;

                    ///  Left arrow - decrease rotation by 5 degree
                    else if (key == GLUT_KEY_LEFT)
                    rotate_y -= 5;

                    else if (key == GLUT_KEY_UP)
                    rotate_x += 5;

                    else if (key == GLUT_KEY_DOWN)
                    rotate_x -= 5;

                    ///  Request display update
                    glutPostRedisplay();

                }

                ///keyboard functions

                void keyboard(unsigned char key,int x,int y){
                sound_is_playing=1;
    ///taking string as input and giving it to key.
                    inc++;
                    yo[inc]=key;

                        if(yo[inc]=='B'&&yo[inc-1]=='T'&&yo[inc-2]=='A')
                        {
                            /// rod a to b
                            if(s1.empty()==1)
                            {
                                cout<<"empty can't move "<<endl;
                                sss1="empty! can't move";
                                sound_is_playing=0;
                                    PlaySound("wrong.wav", NULL, SND_ASYNC|SND_FILENAME);
                            }
                            else{
                                if(s2.empty()||s1.top_ele()<s2.top_ele())
                                {
                                    int i1=s1.Pop();
                                    s2.Push(i1);
                                    cout<<"element "<<i1<< " moved from s1 to s2 "<<endl;
                                    sss1="element "+to_string(i1)+ " moved from s1 to s2";
                                    sound_is_playing=0;

                                    PlaySound("disk.wav", NULL, SND_ASYNC|SND_FILENAME);
                                    disk[i1].xcoord=0;
                                    disk[i1].ycoord=s2.noEle()+disk[num_disks-1].ycoord-0.5;
                                    user_solution<<key<<i1<<endl;
                                    moves++;
                                }
                                else
                                 {
                                    cout<<"invalid move"<<endl;sound_is_playing=0;sss1="invalid move";
                                    PlaySound("wrong.wav", NULL, SND_ASYNC|SND_FILENAME);
                                 }
                            }


                        }
                    else if(yo[inc]=='C'&&yo[inc-1]=='T'&&yo[inc-2]=='A')
                        {
                           /// rod a to c
                            if(s1.empty()==1)
                            {
                                cout<<"empty can't move "<<endl;sss1="empty! can't move";
                                sound_is_playing=0;
                                    PlaySound("wrong.wav", NULL, SND_ASYNC|SND_FILENAME);
                            }
                            else{
                                if(s3.empty()||s1.top_ele()<s3.top_ele())
                                {
                                    int i1=s1.Pop();
                                    s3.Push(i1);
                                    cout<<"element "<<i1<< " moved from s1 to s3 "<<endl;sss1="element "+to_string(i1)+" moved from s1 to s3 ";
                                    sound_is_playing=0;

                                    PlaySound("disk.wav", NULL, SND_ASYNC|SND_FILENAME);
                                    disk[i1].xcoord=-1;
                                    disk[i1].ycoord=s3.noEle()+disk[num_disks-1].ycoord-0.5;
                                    user_solution<<key<<i1<<endl;
                                    moves++;
                                }
                                else
                                 {
                                    cout<<"invalid move"<<endl;sound_is_playing=0;sss1="invalid move";
                                    PlaySound("wrong.wav", NULL, SND_ASYNC|SND_FILENAME);
                                 }
                            }


                        }
                       else if(yo[inc]=='A'&&yo[inc-1]=='T'&&yo[inc-2]=='B')
                       {
                          /// rod b to a
                          if(s2.empty()==1)
                            {
                                cout<<"empty can't move "<<endl;sss1="empty! can't move";
                                sound_is_playing=0;
                                    PlaySound("wrong.wav", NULL, SND_ASYNC|SND_FILENAME);
                            }
                else{
                    if(s1.empty()||s2.top_ele()<s1.top_ele())
                                {
                                    int i1=s2.Pop();
                                    s1.Push(i1);
                                    cout<<"element "<<i1<< " moved from s2 to s1 "<<endl;sss1="element "+to_string(i1)+" moved from s2 to s1 ";
                                    sound_is_playing=0;

                                    PlaySound("disk.wav", NULL, SND_ASYNC|SND_FILENAME);
                                    disk[i1].xcoord=1;
                                    disk[i1].ycoord=s1.noEle()-0.1;
                                    user_solution<<key<<" "<<i1<<endl;
                                    moves++;
                                }
                                else
                                 {
                                    cout<<"invalid move "<<endl;sound_is_playing=0;sss1="invalid move";
                                    PlaySound("wrong.wav", NULL, SND_ASYNC|SND_FILENAME);
                                 }
                }



                       }
                       else if(yo[inc]=='C'&&yo[inc-1]=='T'&&yo[inc-2]=='B')
                        {
                           /// rod b to c
                           if(s2.empty()==1)
                            {
                                cout<<"empty can't move "<<endl;sss1="empty! can't move";
                                sound_is_playing=0;
                                    PlaySound("wrong.wav", NULL, SND_ASYNC|SND_FILENAME);
                            }
                            else
                            {
                                if(s3.empty()||s2.top_ele()<s3.top_ele())
                                {
                                    int i1=s2.Pop();
                                    s3.Push(i1);
                                    cout<<"element "<<i1<< " moved from s2 to s3 "<<endl;sss1="element "+to_string(i1)+" moved from s2 to s3 ";
                                    sound_is_playing=0;

                                    PlaySound("disk.wav", NULL, SND_ASYNC|SND_FILENAME);
                                    disk[i1].xcoord=-1;
                                    disk[i1].ycoord=s3.noEle()+disk[num_disks-1].ycoord-0.5;
                                    user_solution<<key<<" "<<i1<<endl;
                                    moves++;
                                }
                                else
                                 {
                                    cout<<"invalid move "<<endl;sss1="invalid move";
                                    sound_is_playing=0;
                                    PlaySound("wrong.wav", NULL, SND_ASYNC|SND_FILENAME);
                                 }

                            }


                        }
                       else if(yo[inc]=='A'&&yo[inc-1]=='T'&&yo[inc-2]=='C')
                        {
                           /// rod c to a
                           if(s3.empty()==1)
                            {
                                cout<<"empty can't move "<<endl;sss1="empty! can't move";
                                sound_is_playing=0;
                                    PlaySound("wrong.wav", NULL, SND_ASYNC|SND_FILENAME);
                            }
                            else
                            {
                                if(s1.empty()||s3.top_ele()<s1.top_ele())
                                {
                                    int i1=s3.Pop();
                                    s1.Push(i1);
                                    cout<<"element "<<i1<< " moved from s3 to s1 "<<endl;sss1="element "+to_string(i1)+" moved from s3 to s1 ";
                                    sound_is_playing=0;

                                    PlaySound("disk.wav", NULL, SND_ASYNC|SND_FILENAME);
                                    disk[i1].xcoord=1;
                                    disk[i1].ycoord=s1.noEle()-0.1;
                                    user_solution<<key<<" "<<i1<<endl;
                                    moves++;
                                }
                                else
                                 {
                                    cout<<"invalid move"<<endl;sss1="invalid move";
                                    sound_is_playing=0;
                                    PlaySound("wrong.wav", NULL, SND_ASYNC|SND_FILENAME);
                                 }

                            }


                        }
                        else if(yo[inc]=='B'&&yo[inc-1]=='T'&&yo[inc-2]=='C')
                        {
                            /// rod c to b
                            if(s3.empty()==1)
                            {
                                cout<<"empty can't move "<<endl;sss1="empty! can't move";
                                sound_is_playing=0;
                                    PlaySound("wrong.wav", NULL, SND_ASYNC|SND_FILENAME);
                            }
                            else
                            {
                                if(s2.empty()||s3.top_ele()<s2.top_ele())
                                {
                                    int i1=s3.Pop();
                                    s2.Push(i1);
                                    cout<<"element "<<i1<< " moved from s3 to s2 "<<endl;sss1="element "+to_string(i1)+" moved from s3 to s2 ";
                                    sound_is_playing=0;

                                    PlaySound("disk.wav", NULL, SND_ASYNC|SND_FILENAME);
                                    disk[i1].xcoord=0;
                                    disk[i1].ycoord=s2.noEle()+disk[num_disks-1].ycoord-0.5;
                                    user_solution<<key<<" "<<i1<<endl;
                                    moves++;
                                }
                                else
                                 {
                                    cout<<"invalid move"<<endl;sss1="invalid move";
                                    sound_is_playing=0;
                                    PlaySound("wrong.wav", NULL, SND_ASYNC|SND_FILENAME);
                                 }

                            }


                        }
                     else if(key=='3')
                    num_disks=3;
                    else if(key=='4')
                    num_disks=4;
                    else if(key=='5')
                    num_disks=5;
                    else if(key=='6')
                    num_disks=6;
                    else if(key=='7')
                    num_disks=7;
                    else if(key=='8')
                    num_disks=8;
                    else if(key=='9')
                    num_disks=9;
                    else if(key=='R')
                        { moves=0;
                            int i;
                        for(i=1;i<=num_disks;i++)
                    {
                        disk[i].number=i;
                        disk[i].radius=3*disk[i].number; ///setting radius to be 3 times the number of disk
                        disk[i].xcoord=1;                ///setting initial x coordinate to be 1 for all
                        disk[i].ycoord=num_disks-disk[i].number-0.08; ///setting ycoordinate to be in opposite order
                        disk[i].zcoord=0;                    ///setting zcoordinte


                        x=x+0.1;			///setting color of the disk.
                    }

    ///pushing elements in stack 1
                    for(i=num_disks;i>=1;i--)
                    {
                        s1.Push(disk[i].number);
                    }


                        }
                else if(key=='H')
                        { moves=0;
                            int i;
                        for(i=1;i<=num_disks;i++)
                    {
                        disk[i].number=i;
                        disk[i].radius=3*disk[i].number; ///setting radius to be 3 times the number of disk
                        disk[i].xcoord=1;                ///setting initial x coordinate to be 1 for all
                        disk[i].ycoord=num_disks-disk[i].number-0.08; ///setting ycoordinate to be in opposite order
                        disk[i].zcoord=0;                    ///setting zcoordinte


                        x=x+0.1;			///setting color of the disk.
                    }


                    for(i=num_disks;i>=1;i--)
                    {
                        s1.Push(disk[i].number);
                    }
                        tower(num_disks,'A','B','C');

                        }
else if(key=='27')
{
    exit(0);

}
                    glutPostRedisplay();
                }

        void mouse(int button, int state, int x, int y)
                {
                    float mx_temp = x;
                    float my_temp = y;
                    float ox = (float)(mx_temp/(400.0));
                    float oy = (float)((-1.0)*(my_temp/(250.0)));
                    ox -=1;
                    oy+=1;
                    if(button==3){
                        zoom+=0.1;
                    }
                    else if(button==4){
                        zoom-=0.1;
                    }
                       glutPostRedisplay();
                }

        void reshape(int w,int h)
                {
                    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
                    glMatrixMode (GL_PROJECTION);
                    glLoadIdentity ();
                    glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
                    glMatrixMode (GL_MODELVIEW);
                }

        void init(){
                    glClearColor(0.0f,0.0f,0.4f,1.0f);
                    ///  Enable Z-buffer depth test
                    glEnable(GL_DEPTH_TEST);
                    glEnable(GL_COLOR_MATERIAL);
                     glPushMatrix();
                }



                /// main() function

                int main(int argc, char* argv[]){


                int i;
                    float x=0;

                    for(i=1;i<=num_disks;i++)
                    {
                        disk[i].number=i;
                        disk[i].radius=3*disk[i].number; ///setting radius to be 3 times the number of disk
                        disk[i].xcoord=1;                ///setting initial x coordinate to be 1 for all
                        disk[i].ycoord=num_disks-disk[i].number-0.08; ///setting ycoordinate to be in opposite order
                        disk[i].zcoord=0;                    ///setting zcoordinte
                        disk[i].cx=((double) rand() / (RAND_MAX));
                        disk[i].cy=((double) rand() / (RAND_MAX));
                        disk[i].cz=((double) rand() / (RAND_MAX));
                        x=x+0.1;			///setting color of the disk.
                    }

        for(i=num_disks;i>=1;i--)
                    {
                        s1.Push(disk[i].number);
                    }

                ///  Initialize GLUT and process user parameters
                    glutInit(&argc,argv);

                    ///  Request double buffered true color window with Z-buffer
                    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

                    glutInitWindowSize (1100,500);

                    glutInitWindowPosition (100, 100);

                    /// Create window
                    glutCreateWindow("Towers Of Hanoi");

                    init();
            glClearColor(1,1,1,1);
                glEnable(GL_CULL_FACE);
                glCullFace(GL_BACK);

                glEnable(GL_DEPTH_TEST);
                glDepthFunc(GL_LESS);

                glEnable(GL_LIGHT0);
                glEnable(GL_NORMALIZE);
                glEnable(GL_COLOR_MATERIAL);
                glEnable(GL_LIGHTING);

                glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
                glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
                glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
                glLightfv(GL_LIGHT0, GL_POSITION, light_position);

                glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
                glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
                glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
                glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
                    /// Callback functions

                    glutKeyboardFunc(keyboard);
                    glutDisplayFunc(display);
                    glutMouseFunc(mouse);
                    glutSpecialFunc(specialKeys);
                    glutReshapeFunc(reshape);
glutMotionFunc(drag);
                    ///  Pass control to GLUT for events
                    glutMainLoop();


                    ///  Return to OS
                    return 0;

                }
