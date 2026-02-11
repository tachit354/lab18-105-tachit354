#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect *r1,Rect *r2){
    double x_start,y_start,x_end,y_end;
    
    double r1_right = r1->x + r1->w;
    double r1_bottom = r1->y - r1->h;
    double r2_right = r2->x + r2->w;
    double r2_bottom = r2->y - r2->h;
    
    if(r1->x > r2->x) x_start = r1->x;
    else x_start = r2->x;
    
    if(r1->y < r2->y) y_start = r1->y;
    else y_start = r2->y;
    
    if(r1_right < r2_right) x_end = r1_right;
    else x_end = r2_right;
    
    if(r1_bottom > r2_bottom) y_end = r1_bottom;
    else y_end = r2_bottom;
    
    double overlap_w = x_end - x_start;
    double overlap_h = y_start - y_end;
    
    if (overlap_w <= 0 || overlap_h <= 0) {
        return 0;
    }
    
    return overlap_w * overlap_h;
}

