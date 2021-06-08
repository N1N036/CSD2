#include "olcConsoleGameEngine.h"
#include <algorithm>

using namespace std;

class olcEngine3D : public olcConsoleGameEngine {
public:
    olcEngine3D() {
        m_sAppName = L"3D Demo";
    }

private:


    float fYaw = 0.0f;        // FPS Camera rotation in XZ plane
    float fTheta = 0.0f;    // Spins World transform


    int
    Triangle_ClipAgainstPlane(vec3d plane_p, vec3d plane_n, triangle &in_tri, triangle &out_tri1, triangle &out_tri2) {
        // Make sure plane normal is indeed normal
        plane_n = Vector_Normalise(plane_n);

        // Return signed shortest distance from point to plane, plane normal must be normalised
        auto dist = [&](vec3d &p) {
            vec3d n = Vector_Normalise(p);
            return (plane_n.x * p.x + plane_n.y * p.y + plane_n.z * p.z - Vector_DotProduct(plane_n, plane_p));
        };

        // Create two temporary storage arrays to classify points either side of plane
        // If distance sign is positive, point lies on "inside" of plane
        vec3d *inside_points[3];
        int nInsidePointCount = 0;
        vec3d *outside_points[3];
        int nOutsidePointCount = 0;

        // Get signed distance of each point in triangle to plane
        float d0 = dist(in_tri.p[0]);
        float d1 = dist(in_tri.p[1]);
        float d2 = dist(in_tri.p[2]);

        if (d0 >= 0) { inside_points[nInsidePointCount++] = &in_tri.p[0]; }
        else { outside_points[nOutsidePointCount++] = &in_tri.p[0]; }
        if (d1 >= 0) { inside_points[nInsidePointCount++] = &in_tri.p[1]; }
        else { outside_points[nOutsidePointCount++] = &in_tri.p[1]; }
        if (d2 >= 0) { inside_points[nInsidePointCount++] = &in_tri.p[2]; }
        else { outside_points[nOutsidePointCount++] = &in_tri.p[2]; }

        // Now classify triangle points, and break the input triangle into
        // smaller output triangles if required. There are four possible
        // outcomes...

        if (nInsidePointCount == 0) {
            // All points lie on the outside of plane, so clip whole triangle
            // It ceases to exist

            return 0; // No returned triangles are valid
        }

        if (nInsidePointCount == 3) {
            // All points lie on the inside of plane, so do nothing
            // and allow the triangle to simply pass through
            out_tri1 = in_tri;

            return 1; // Just the one returned original triangle is valid
        }

        if (nInsidePointCount == 1 && nOutsidePointCount == 2) {
            // Triangle should be clipped. As two points lie outside
            // the plane, the triangle simply becomes a smaller triangle

            // Copy appearance info to new triangle
            out_tri1.col = in_tri.col;
            out_tri1.sym = in_tri.sym;

            // The inside point is valid, so keep that...
            out_tri1.p[0] = *inside_points[0];

            // but the two new points are at the locations where the
            // original sides of the triangle (lines) intersect with the plane
            out_tri1.p[1] = Vector_IntersectPlane(plane_p, plane_n, *inside_points[0], *outside_points[0]);
            out_tri1.p[2] = Vector_IntersectPlane(plane_p, plane_n, *inside_points[0], *outside_points[1]);

            return 1; // Return the newly formed single triangle
        }

        if (nInsidePointCount == 2 && nOutsidePointCount == 1) {
            // Triangle should be clipped. As two points lie inside the plane,
            // the clipped triangle becomes a "quad". Fortunately, we can
            // represent a quad with two new triangles

            // Copy appearance info to new triangles
            out_tri1.col = in_tri.col;
            out_tri1.sym = in_tri.sym;

            out_tri2.col = in_tri.col;
            out_tri2.sym = in_tri.sym;

            // The first triangle consists of the two inside points and a new
            // point determined by the location where one side of the triangle
            // intersects with the plane
            out_tri1.p[0] = *inside_points[0];
            out_tri1.p[1] = *inside_points[1];
            out_tri1.p[2] = Vector_IntersectPlane(plane_p, plane_n, *inside_points[0], *outside_points[0]);

            // The second triangle is composed of one of he inside points, a
            // new point determined by the intersection of the other side of the
            // triangle and the plane, and the newly created point above
            out_tri2.p[0] = *inside_points[1];
            out_tri2.p[1] = out_tri1.p[2];
            out_tri2.p[2] = Vector_IntersectPlane(plane_p, plane_n, *inside_points[1], *outside_points[0]);

            return 2; // Return two newly formed triangles which form a quad
        }
    }


    // Taken From Command Line Webcam Video
    CHAR_INFO GetColour(float lum) {
        short bg_col, fg_col;
        wchar_t sym;
        int pixel_bw = (int) (13.0f * lum);
        switch (pixel_bw)
        {
            case 0: bg_col = BG_BLACK; fg_col = FG_BLACK; sym = PIXEL_SOLID; break;

            case 1: bg_col = BG_BLACK; fg_col = FG_DARK_GREY; sym = PIXEL_QUARTER; break;
            case 2: bg_col = BG_BLACK; fg_col = FG_DARK_GREY; sym = PIXEL_HALF; break;
            case 3: bg_col = BG_BLACK; fg_col = FG_DARK_GREY; sym = PIXEL_THREEQUARTERS; break;
            case 4: bg_col = BG_BLACK; fg_col = FG_DARK_GREY; sym = PIXEL_SOLID; break;

            case 5: bg_col = BG_GREY; fg_col = FG_GREY; sym = PIXEL_QUARTER; break;
            case 6: bg_col = BG_GREY; fg_col = FG_GREY; sym = PIXEL_HALF; break;
            case 7: bg_col = BG_GREY; fg_col = FG_GREY; sym = PIXEL_THREEQUARTERS; break;
            case 8: bg_col = BG_GREY; fg_col = FG_GREY; sym = PIXEL_SOLID; break;

            case 9:  bg_col = BG_DARK_BLUE; fg_col = FG_WHITE; sym = PIXEL_QUARTER; break;
            case 10: bg_col = BG_DARK_BLUE; fg_col = FG_WHITE; sym = PIXEL_HALF; break;
            case 11: bg_col = BG_DARK_BLUE; fg_col = FG_WHITE; sym = PIXEL_THREEQUARTERS; break;
            case 12: bg_col = BG_DARK_BLUE; fg_col = FG_WHITE; sym = PIXEL_SOLID; break;
            default:
                bg_col = BG_DARK_BLUE; fg_col = BG_CYAN; sym = PIXEL_SOLID;
        }

        CHAR_INFO c;
        c.Attributes = bg_col | fg_col;
        c.Char.UnicodeChar = sym;
        return c;
    }

public:


    bool OnUserUpdate(float fElapsedTime) override
    {
        if (GetKey(VK_UP).bHeld)
            vCamera.y += 8.0f * fElapsedTime;	// Travel Upwards

        if (GetKey(VK_DOWN).bHeld)
            vCamera.y -= 8.0f * fElapsedTime;	// Travel Downwards


        // Dont use these two in FPS mode, it is confusing :P
        if (GetKey(VK_LEFT).bHeld)
            vCamera.x -= 8.0f * fElapsedTime;	// Travel Along X-Axis

        if (GetKey(VK_RIGHT).bHeld)
            vCamera.x += 8.0f * fElapsedTime;	// Travel Along X-Axis


        vec3d vForward = Vector_Mul(vLookDir, 5.0f * fElapsedTime);

        // Standard FPS Control scheme, but turn instead of strafe
        if (GetKey(L'W').bHeld)
            vCamera = Vector_Add(vCamera, vForward);

        if (GetKey(L'S').bHeld)
            vCamera = Vector_Sub(vCamera, vForward);

        if (GetKey(L'A').bHeld)
            fYaw -= 2.0f * fElapsedTime;

        if (GetKey(L'D').bHeld)
            fYaw += 2.0f * fElapsedTime;




        // Set up "World Tranmsform" though not updating theta
        // makes this a bit redundant
        mat4x4 matRotZ, matRotX;
        //fTheta += 1.0f * fElapsedTime; // Uncomment to spin me right round baby right round
        matRotZ = Matrix_MakeRotationZ(fTheta * 0.5f);
        matRotX = Matrix_MakeRotationX(fTheta);

        mat4x4 matTrans;
        matTrans = Matrix_MakeTranslation(0.0f, 0.0f, 5.0f);

        mat4x4 matWorld;
        matWorld = Matrix_MakeIdentity();	// Form World Matrix
        matWorld = Matrix_MultiplyMatrix(matRotZ, matRotX); // Transform by rotation
        matWorld = Matrix_MultiplyMatrix(matWorld, matTrans); // Transform by translation

        // Create "Point At" Matrix for camera
        vec3d vUp = { 0,1,0 };
        vec3d vTarget = { 0,0,1 };
        mat4x4 matCameraRot = Matrix_MakeRotationY(fYaw);
        vLookDir = Matrix_MultiplyVector(matCameraRot, vTarget);
        vTarget = Vector_Add(vCamera, vLookDir);
        mat4x4 matCamera = Matrix_PointAt(vCamera, vTarget, vUp);

        // Make view matrix from camera
        mat4x4 matView = Matrix_QuickInverse(matCamera);

        // Store triagles for rastering later
        vector<triangle> vecTrianglesToRaster;

        // Draw Triangles
        for (auto tri : meshCube.tris)
        {
            triangle triProjected, triTransformed, triViewed;

            // World Matrix Transform
            triTransformed.p[0] = Matrix_MultiplyVector(matWorld, tri.p[0]);
            triTransformed.p[1] = Matrix_MultiplyVector(matWorld, tri.p[1]);
            triTransformed.p[2] = Matrix_MultiplyVector(matWorld, tri.p[2]);

            // Calculate triangle Normal
            vec3d normal, line1, line2;

            // Get lines either side of triangle
            line1 = Vector_Sub(triTransformed.p[1], triTransformed.p[0]);
            line2 = Vector_Sub(triTransformed.p[2], triTransformed.p[0]);

            // Take cross product of lines to get normal to triangle surface
            normal = Vector_CrossProduct(line1, line2);

            // You normally need to normalise a normal!
            normal = Vector_Normalise(normal);

            // Get Ray from triangle to camera
            vec3d vCameraRay = Vector_Sub(triTransformed.p[0], vCamera);

            // If ray is aligned with normal, then triangle is visible
            if (Vector_DotProduct(normal, vCameraRay) < 100.0f)
            {
                // Illumination
                vec3d light_direction = { 0.0f, 0.8f, -0.3f };
                light_direction = Vector_Normalise(light_direction);

                // How "aligned" are light direction and triangle surface normal?
                float dp = max(0.1f, Vector_DotProduct(light_direction, normal));

                // Choose console colours as required (much easier with RGB)
                CHAR_INFO c = GetColour(dp);
                triTransformed.col = c.Attributes;
                triTransformed.sym = c.Char.UnicodeChar;

                // Convert World Space --> View Space
                triViewed.p[0] = Matrix_MultiplyVector(matView, triTransformed.p[0]);
                triViewed.p[1] = Matrix_MultiplyVector(matView, triTransformed.p[1]);
                triViewed.p[2] = Matrix_MultiplyVector(matView, triTransformed.p[2]);
                triViewed.sym = triTransformed.sym;
                triViewed.col = triTransformed.col;

                // Clip Viewed Triangle against near plane, this could form two additional
                // additional triangles.
                int nClippedTriangles = 0;
                triangle clipped[2];
                nClippedTriangles = Triangle_ClipAgainstPlane({ 0.0f, 0.0f, 0.1f }, { 0.0f, 0.0f, 1.0f }, triViewed, clipped[0], clipped[1]);

                // We may end up with multiple triangles form the clip, so project as
                // required
                for (int n = 0; n < nClippedTriangles; n++)
                {
                    // Project triangles from 3D --> 2D
                    triProjected.p[0] = Matrix_MultiplyVector(matProj, clipped[n].p[0]);
                    triProjected.p[1] = Matrix_MultiplyVector(matProj, clipped[n].p[1]);
                    triProjected.p[2] = Matrix_MultiplyVector(matProj, clipped[n].p[2]);
                    triProjected.col = clipped[n].col;
                    triProjected.sym = clipped[n].sym;

                    // Scale into view, we moved the normalising into cartesian space
                    // out of the matrix.vector function from the previous videos, so
                    // do this manually
                    triProjected.p[0] = Vector_Div(triProjected.p[0], triProjected.p[0].w);
                    triProjected.p[1] = Vector_Div(triProjected.p[1], triProjected.p[1].w);
                    triProjected.p[2] = Vector_Div(triProjected.p[2], triProjected.p[2].w);

                    // X/Y are inverted so put them back
                    triProjected.p[0].x *= -1.0f;
                    triProjected.p[1].x *= -1.0f;
                    triProjected.p[2].x *= -1.0f;
                    triProjected.p[0].y *= -1.0f;
                    triProjected.p[1].y *= -1.0f;
                    triProjected.p[2].y *= -1.0f;

                    // Offset verts into visible normalised space
                    vec3d vOffsetView = { 1,1,0 };
                    triProjected.p[0] = Vector_Add(triProjected.p[0], vOffsetView);
                    triProjected.p[1] = Vector_Add(triProjected.p[1], vOffsetView);
                    triProjected.p[2] = Vector_Add(triProjected.p[2], vOffsetView);
                    triProjected.p[0].x *= 0.5f * (float)ScreenWidth();
                    triProjected.p[0].y *= 0.5f * (float)ScreenHeight();
                    triProjected.p[1].x *= 0.5f * (float)ScreenWidth();
                    triProjected.p[1].y *= 0.5f * (float)ScreenHeight();
                    triProjected.p[2].x *= 0.5f * (float)ScreenWidth();
                    triProjected.p[2].y *= 0.5f * (float)ScreenHeight();

                    // Store triangle for sorting
                    vecTrianglesToRaster.push_back(triProjected);
                }
            }
        }

        // Sort triangles from back to front
        sort(vecTrianglesToRaster.begin(), vecTrianglesToRaster.end(), [](triangle &t1, triangle &t2)
        {
            float z1 = (t1.p[0].z + t1.p[1].z + t1.p[2].z) / 3.0f;
            float z2 = (t2.p[0].z + t2.p[1].z + t2.p[2].z) / 3.0f;
            return z1 > z2;
        });

        // Clear Screen
        Fill(0, 0, ScreenWidth(), ScreenHeight(), PIXEL_SOLID, FG_BLACK);

        // Loop through all transformed, viewed, projected, and sorted triangles
        for (auto &triToRaster : vecTrianglesToRaster)
        {
            // Clip triangles against all four screen edges, this could yield
            // a bunch of triangles, so create a queue that we traverse to
            //  ensure we only test new triangles generated against planes
            triangle clipped[2];
            list<triangle> listTriangles;

            // Add initial triangle
            listTriangles.push_back(triToRaster);
            int nNewTriangles = 1;

            for (int p = 0; p < 4; p++)
            {
                int nTrisToAdd = 0;
                while (nNewTriangles > 0)
                {
                    // Take triangle from front of queue
                    triangle test = listTriangles.front();
                    listTriangles.pop_front();
                    nNewTriangles--;

                    // Clip it against a plane. We only need to test each
                    // subsequent plane, against subsequent new triangles
                    // as all triangles after a plane clip are guaranteed
                    // to lie on the inside of the plane. I like how this
                    // comment is almost completely and utterly justified
                    switch (p)
                    {
                        case 0:	nTrisToAdd = Triangle_ClipAgainstPlane({ 0.0f, 0.0f, 0.0f }, { 0.0f, 1.0f, 0.0f }, test, clipped[0], clipped[1]); break;
                        case 1:	nTrisToAdd = Triangle_ClipAgainstPlane({ 0.0f, (float)ScreenHeight() - 1, 0.0f }, { 0.0f, -1.0f, 0.0f }, test, clipped[0], clipped[1]); break;
                        case 2:	nTrisToAdd = Triangle_ClipAgainstPlane({ 0.0f, 0.0f, 0.0f }, { 1.0f, 0.0f, 0.0f }, test, clipped[0], clipped[1]); break;
                        case 3:	nTrisToAdd = Triangle_ClipAgainstPlane({ (float)ScreenWidth() - 1, 0.0f, 0.0f }, { -1.0f, 0.0f, 0.0f }, test, clipped[0], clipped[1]); break;
                    }

                    // Clipping may yield a variable number of triangles, so
                    // add these new ones to the back of the queue for subsequent
                    // clipping against next planes
                    for (int w = 0; w < nTrisToAdd; w++)
                        listTriangles.push_back(clipped[w]);
                }
                nNewTriangles = listTriangles.size();
            }


            // Draw the transformed, viewed, clipped, projected, sorted, clipped triangles
            for (auto &t : listTriangles)
            {
                FillTriangle(t.p[0].x, t.p[0].y, t.p[1].x, t.p[1].y, t.p[2].x, t.p[2].y, t.sym, t.col);
                DrawTriangle(t.p[0].x, t.p[0].y, t.p[1].x, t.p[1].y, t.p[2].x, t.p[2].y, PIXEL_SOLID, FG_CYAN);
            }
        }


        return true;
    }

};