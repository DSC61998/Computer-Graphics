#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<window.h>
#define X_COORDINATE 0
#define Y_COORDINATE 1
#define Z_COORDINATE 2
#define b0 0
#define b1 1
#define b2 2
#define b3 3

float xBoundaryRight, xBoundaryLeft, yBoundaryUpper, yBoundaryLower;
float p1[3], p2[3], p3[3], p4[3];
/* corners of the clipping rectangle, clock-wise from top left */

float givenLineSegmentP1[3], givenLineSegmentP2[3];
float clippedLineP1[3], clippedLineP2[3];

void display ();
void myInit ();

int main (int argc, char **argv) {

    char outP1[4], outP2[4], outTemp[4]; /* b0, b1, b2 and b3 as described in the text book. */
    int i;
    float m, c, tempPoint[3];

    printf ("Enter X-Boundary (right): ");
    scanf ("%f", &xBoundaryRight);
    printf ("Enter X-Boundary (left): ");
    scanf ("%f", &xBoundaryLeft);
    printf ("Enter Y-Boundary (upper): ");
    scanf ("%f", &yBoundaryUpper);
    printf ("Enter Y-Boundary (lower): ");
    scanf ("%f", &yBoundaryLower);

    printf ("Enter the first point of the the line segment to be clipped (x, y): ");
    scanf ("%f %f", &givenLineSegmentP1[X_COORDINATE], &givenLineSegmentP1[Y_COORDINATE]);

    printf ("Enter the second point of the the line segment to be clipped (x, y): ");
    scanf ("%f %f", &givenLineSegmentP2[X_COORDINATE], &givenLineSegmentP2[Y_COORDINATE]);

    givenLineSegmentP2[Z_COORDINATE] = givenLineSegmentP1[Z_COORDINATE] = 0;

    /* Now calcluate the corners of the clipping rectangle */

    p1[X_COORDINATE] = xBoundaryLeft;
    p1[Y_COORDINATE] = yBoundaryUpper;
    p1[Z_COORDINATE] = 0;

    p2[X_COORDINATE] = xBoundaryRight;
    p2[Y_COORDINATE] = yBoundaryUpper;
    p2[Z_COORDINATE] = 0;

    p3[X_COORDINATE] = xBoundaryRight;
    p3[Y_COORDINATE] = yBoundaryLower;
    p3[Z_COORDINATE] = 0;

    p4[X_COORDINATE] = xBoundaryLeft;
    p4[Y_COORDINATE] = yBoundaryLower;
    p4[Z_COORDINATE] = 0;

    /* Do the required calculations. */
    /* b0 is 1 if point is outside of yBoundaryUpper
       b1 is 1 if point is outside of yBoundaryLower
       b2 is 1 if point is outside of xBoundaryLeft and
       b3 is 1 if point is outside of xBoundaryRight. */

    outP1[b0] = (givenLineSegmentP1[Y_COORDINATE] > yBoundaryUpper) ? 1 : 0;
    outP1[b1] = (givenLineSegmentP1[Y_COORDINATE] < yBoundaryLower) ? 1 : 0;
    outP1[b2] = (givenLineSegmentP1[X_COORDINATE] < xBoundaryLeft) ? 1 : 0;
    outP1[b3] = (givenLineSegmentP1[X_COORDINATE] > xBoundaryRight) ? 1 : 0;

    outP2[b0] = (givenLineSegmentP2[Y_COORDINATE] > yBoundaryUpper) ? 1 : 0;
    outP2[b1] = (givenLineSegmentP2[Y_COORDINATE] < yBoundaryLower) ? 1 : 0;
    outP2[b2] = (givenLineSegmentP2[X_COORDINATE] < xBoundaryLeft) ? 1 : 0;
    outP2[b3] = (givenLineSegmentP2[X_COORDINATE] > xBoundaryRight) ? 1 : 0;


    /* We now have four cases to consider according to the Cohen-Sutherland Algorithm. */
    /* The point may be out of more than one side. In which case, we first clip w.r.t
       one side and continue the loop (updating the outP[] and clippedLine[] arrays */

    for (i = 0; i < 3; i++) clippedLineP1[i] = givenLineSegmentP1[i];
    for (i = 0; i < 3; i++) clippedLineP2[i] = givenLineSegmentP2[i];
    /* Henceforth, only clippedLineP[] will be used. */
    while (1) {
    /* case 1 */
    if (outP1[b0] == 0 && outP1[b1] == 0 && outP1[b2] == 0 && outP1[b3] == 0 &&
        outP2[b0] == 0 && outP2[b1] == 0 && outP2[b2] == 0 && outP2[b3] == 0) {
        break;
    }

    /* case 2. One point inside and the other outside the rect. Split into two cases. */
    /* case 2a: outP1 != 0 && outP2 == 0: First point is outside and second inside. */
    else if ((outP1[b0] != 0 || outP1[b1] != 0 || outP1[b2] != 0 || outP1[b3] != 0) &&
         (outP2[b0] == 0 && outP2[b1] == 0 && outP2[b2] == 0 && outP2[b3] == 0)) {
        if (clippedLineP1[X_COORDINATE] == clippedLineP2[X_COORDINATE]) {
        /* then m = (y2-y1)/(x2-x1) would be infinity. */
        if (outP1[b0] == 1) {
            clippedLineP1[Y_COORDINATE] = yBoundaryUpper;
            outP1[b0] = 0;
        }
        else {
            clippedLineP1[Y_COORDINATE] = yBoundaryLower;
            outP1[b2] = 0;
        }
        continue;
        }
        m = clippedLineP1[Y_COORDINATE]-clippedLineP2[Y_COORDINATE];
        m /= clippedLineP1[X_COORDINATE]-clippedLineP2[X_COORDINATE];

        if (m == 0) {
        if (outP1[b2] == 1) {
            clippedLineP1[X_COORDINATE] = xBoundaryLeft;
            outP1[b2] = 0;
        }
        else {
            clippedLineP1[X_COORDINATE] = xBoundaryRight;
            outP1[b3] = 0;
        }
        continue;
        }
        /* Line is neither horizontal nor vertical at this point */
        /* We try to clip whichever bound exceeds that we see first. After clipping
           at that point, we immediately check if the other (if any) has been clipped
           too. */

        c = clippedLineP1[Y_COORDINATE]-(m*clippedLineP1[X_COORDINATE]);
        if (outP1[b0] == 1) {
        clippedLineP1[Y_COORDINATE] = yBoundaryUpper;
        clippedLineP1[X_COORDINATE] = (yBoundaryUpper-c)/m;
        outP1[b0] = 0;
        if (clippedLineP1[X_COORDINATE] <= xBoundaryRight &&
            clippedLineP1[X_COORDINATE] >= xBoundaryLeft) {
            outP1[b2] = outP1[b3] = 0;
            break;
        }
        continue;
        }
        if (outP1[b1] == 1) {
        clippedLineP1[Y_COORDINATE] = yBoundaryLower;
        clippedLineP1[X_COORDINATE] = (yBoundaryLower-c)/m;
        outP1[b1] = 0;
        if (clippedLineP1[X_COORDINATE] <= xBoundaryRight &&
            clippedLineP1[X_COORDINATE] >= xBoundaryLeft) {
            outP1[b2] = outP1[b3] = 0;
            break;
        }
        continue;
        }
        if (outP1[b2] == 1) {
        clippedLineP1[X_COORDINATE] = xBoundaryLeft;
        clippedLineP1[Y_COORDINATE] = (m*xBoundaryLeft)+c;
        outP1[b2] = 0;
        if (clippedLineP1[Y_COORDINATE] <= yBoundaryUpper &&
            clippedLineP1[Y_COORDINATE] >= yBoundaryLower) {
            outP1[b0] = outP1[b1] = 0;
            break;
        }
        continue;
        }
        if (outP1[b3] == 1) {
        clippedLineP1[X_COORDINATE] = xBoundaryRight;
        clippedLineP1[Y_COORDINATE] = (m*xBoundaryRight)+c;
        outP1[b3] = 0;
        if (clippedLineP1[Y_COORDINATE] <= yBoundaryUpper &&
            clippedLineP1[Y_COORDINATE] >= yBoundaryLower) {
            outP1[b0] = outP1[b1] = 0;
            break;
        }
        continue;
        }
    }
    /* Case2b: If first point is inside and second point is outside. */
    else if ((outP2[b0] != 0 || outP2[b1] != 0 || outP2[b2] != 0 || outP2[b3] != 0) &&
         (outP1[b0] == 0 && outP1[b1] == 0 && outP1[b2] == 0 && outP1[b3] == 0)) {
        /* Exchange first and second points completely including outP[] and continue. */
        for (i = 0; i < 3; i++) tempPoint[i] = clippedLineP1[i];
        for (i = 0; i < 3; i++) clippedLineP1[i] = clippedLineP2[i];
        for (i = 0; i < 3; i++) clippedLineP2[i] = tempPoint[i];

        for (i = 0; i < 4; i++) outTemp[i] = outP1[i];
        for (i = 0; i < 4; i++) outP1[i] = outP2[i];
        for (i = 0; i < 4; i++) outP2[i] = outTemp[i];
        continue;
    }

    /* Case 3. if (outP1 & outP2 != 0): Both points exceed the same boundary. */
    else if  ((outP1[b0] && outP2[b0] == 1) || (outP1[b1] && outP2[b1] == 1) ||
          (outP1[b2] && outP2[b2] == 1) || (outP1[b3] && outP2[b3] == 1)) {
        /* set clippedLineP1 and clippedLineP2 both to 0,0,0 */
        for (i = 0; i < 3; i++) clippedLineP2[i] = clippedLineP1[i] = 0;
        break;
    }
    /* case 4. Both endpoints are outside, but of different edges. */
    else {
        /* Determine the points of intersection of the line with the four boundaries
           and determine the outcode for each of these intersection points. We can
           then estimate if the line is entirely out of the boundary or not. */
        float intersectionP1[3], intersectionP2[3], intersectionP3[3], intersectionP4[3];
        int validIntersections = 0;

        /* check for special cases where line is horizontal or vertical. */
        if (clippedLineP1[X_COORDINATE] == clippedLineP2[X_COORDINATE]) {
        /* The line starts from above yBoundaryUpper and ends below yBoundaryLower. */
        clippedLineP1[Y_COORDINATE] = yBoundaryUpper;
        clippedLineP2[Y_COORDINATE] = yBoundaryLower;
        break;
        }
        if (clippedLineP1[Y_COORDINATE] == clippedLineP2[Y_COORDINATE]) {
        /* The line starts from left of xBoundaryLeft and ends after xBoundaryRight. */
        clippedLineP1[X_COORDINATE] = xBoundaryLeft;
        clippedLineP2[X_COORDINATE] = xBoundaryRight;
        break;
        }
        /* Line is neither vertical nor horizontal. Do all four intersections. */
        m = clippedLineP1[Y_COORDINATE] - clippedLineP2[Y_COORDINATE];
        m /= clippedLineP1[X_COORDINATE] - clippedLineP2[X_COORDINATE];
        c = clippedLineP1[Y_COORDINATE] - (m*clippedLineP1[X_COORDINATE]);

        /* Intersection with yBoundaryUpper */
        intersectionP1[Y_COORDINATE] = yBoundaryUpper;
        intersectionP1[X_COORDINATE] = (yBoundaryUpper-c)/m;
        intersectionP1[Z_COORDINATE] = 0;

        /* Intersection with yBoundaryLower */
        intersectionP2[Y_COORDINATE] = yBoundaryLower;
        intersectionP2[X_COORDINATE] = (yBoundaryLower-c)/m;
        intersectionP2[Z_COORDINATE] = 0;

        /* Intersection with xBoundaryLeft */
        intersectionP3[X_COORDINATE] = xBoundaryLeft;
        intersectionP3[Y_COORDINATE] = (m*xBoundaryLeft)+c;
        intersectionP3[Z_COORDINATE] = 0;

        /* Intersection with xBoundaryRight */
        intersectionP4[X_COORDINATE] = xBoundaryRight;
        intersectionP4[Y_COORDINATE] = (m*xBoundaryRight)+c;
        intersectionP4[Z_COORDINATE] = 0;

        /* If all these intersections are "outside", line is outside.
           If atleast one intersection is inside, there is one more
           intersection that is inside. These two intersections form
           the clipped line. (unless the line passes through a corner). */
        /* The line cannot pass through the viewing rectange at more
           than two points. If there are more than two points (among
           the above intersection points) that are inside the viewing
           rectangle, some are identical. We need to set clippedLineP1
           and clippedLineP2 to these two points (if any). */
        /* When we find the 2nd valid intersection, we verify that it is
           not the same as the first and then only use it. At the end, if
           we have only one valid intersection, we reset both end points to
           0,0,0 so that the line is not displayed as clipped. */
        /* WE NEED TO FIND UNIQUE INTERSECTION POINTS THAT ARE INSIDE (if any).  */

        /* intersectionP1 (intersection with yBoundaryUpper). */
        if (intersectionP1[X_COORDINATE] <= xBoundaryRight &&
        intersectionP1[X_COORDINATE] >= xBoundaryLeft) {
        for (i = 0; i < 3; i++) clippedLineP1[i] = intersectionP1[i];
        validIntersections++;
        }
        /* intersectionP2 (intersection with yBoundaryLower). */
        if (intersectionP2[X_COORDINATE] <= xBoundaryRight &&
        intersectionP2[X_COORDINATE] >= xBoundaryLeft) {
        if (validIntersections == 1) {
            /* we need to verify if its the same point as the first one. */
            if (intersectionP2[X_COORDINATE] == clippedLineP1[X_COORDINATE] &&
            intersectionP2[Y_COORDINATE] == clippedLineP1[Y_COORDINATE] &&
            intersectionP2[Z_COORDINATE] == clippedLineP1[Z_COORDINATE])
            /* do nothing. */ ;
            else {
            for (i = 0; i < 3; i++) clippedLineP2[i] = intersectionP2[i];
            validIntersections++;
            break;
            }
        }
        else {
            for (i = 0; i < 3; i++) clippedLineP1[i] = intersectionP2[i];
            validIntersections++;
        }
        }
        /* intersectionP3 (intersection with xBoundaryLeft). */
        if (intersectionP3[Y_COORDINATE] <= yBoundaryUpper &&
        intersectionP3[Y_COORDINATE] >= yBoundaryLower) {
        if (validIntersections == 1) {
            /* we need to verify if its the same point as the first one. */
            if (intersectionP3[X_COORDINATE] == clippedLineP1[X_COORDINATE] &&
            intersectionP3[Y_COORDINATE] == clippedLineP1[Y_COORDINATE] &&
            intersectionP3[Z_COORDINATE] == clippedLineP1[Z_COORDINATE])
            /* do nothing. */ ;
            else {
            for (i = 0; i < 3; i++) clippedLineP2[i] = intersectionP3[i];
            validIntersections++;
            break;
            }
        }
        else {
            for (i = 0; i < 3; i++) clippedLineP1[i] = intersectionP3[i];
            validIntersections++;
        }
        }
        /* intersectionP4 (intersection with xBoundaryRight */
        if (intersectionP4[Y_COORDINATE] <= yBoundaryUpper &&
        intersectionP4[Y_COORDINATE] >= yBoundaryLower) {
        if (validIntersections == 1) {
            /* we need to verify if its the same point as the first one. */
            if (intersectionP4[X_COORDINATE] == clippedLineP1[X_COORDINATE] &&
            intersectionP4[Y_COORDINATE] == clippedLineP1[Y_COORDINATE] &&
            intersectionP4[Z_COORDINATE] == clippedLineP1[Z_COORDINATE])
            /* do nothing. */ ;
            else {
            for (i = 0; i < 3; i++) clippedLineP2[i] = intersectionP4[i];
            validIntersections++;
            break;
            }
        }
        else {
            for (i = 0; i < 3; i++) clippedLineP1[i] = intersectionP4[i];
            validIntersections++;
        }
        }

        /* If validIntersections <= 1 at this point, we set both clippedLineP1
           and clippedLineP2 to 0,0,0. Only one validIntersection means that
           the line just passes through a corner of the viewing rectangle. */
        if (validIntersections <= 1)
        for (i = 0; i < 3; i++) clippedLineP2[i] = clippedLineP1[i] = 0;
        break;
    }
    }

    glutInit (&argc, argv);
    glutCreateWindow ("Cohen-Sutherland Line Clipping");
    glutInitWindowPosition (400, 400);
    glutInitWindowSize (640, 480);
    glutDisplayFunc (display);
    myInit();
    glutMainLoop();
}

void myInit () {

    glClearColor (1.0, 1.0, 1.0, 1.0);
    glPointSize (1);
    glColor3f (0.0, 0.0, 0.0);

    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    glOrtho (-50.0, 50.0, -50.0, 50.0, -50.0, 50.0);
    glMatrixMode (GL_MODELVIEW);
}

void display () {

    /* Clipped line is displayed in red, and unclipped in black. */

    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0, 0.0, 0.0);
    glBegin (GL_LINE_LOOP);
    glVertex3fv (p1);
    glVertex3fv (p2);
    glVertex3fv (p3);
    glVertex3fv (p4);
    glEnd ();
    glBegin (GL_LINES);
    glVertex3fv (givenLineSegmentP1);
    glVertex3fv (givenLineSegmentP2);
    glColor3f (1.0, 0.0, 0.0);
    glLineWidth (2);
    glVertex3fv (clippedLineP1);
    glVertex3fv (clippedLineP2);
    glEnd();

    glFlush();
}
