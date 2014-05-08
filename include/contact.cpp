#include "contact.h"

using namespace std;

void contactListener::BeginContact (b2Contact * contact)
{
		  char * ud;
		  b2Vec2 pos;
		  float angle = 0.0f;
		  b2BodyType dyn = myPlayer->GetType();
//		  b2BodyType stat = gameFloor->GetType();
//		  b2BodyType kin = platform->GetType();
		  ud = (char *)(contact->GetFixtureA()->GetBody()->GetUserData());
		  if (ud)
		  {
					 if (ud == (char *)"player")
					 {
								//								Log("Player hit something\n");
					 }
					 else if (contains(ud, (const char *)"bullet"))
					 {
//								Log("bullet hit something\n");
//								Log("FixtureA's user data:\n\t%s\n", ((char *)(contact->GetFixtureA()->GetBody()->GetUserData())));
//								Log("FixtureB's user data:\n\t%s\n", ((char *)(contact->GetFixtureB()->GetBody()->GetUserData())));
								if (contains(((char *)(contact->GetFixtureB()->GetBody()->GetUserData())), "portalable"))
								{
//										  Log("you shot a portalable object!\n");
										  pos = (b2Vec2)(contact->GetFixtureA()->GetBody()->GetWorldCenter());
										  angle = (float)(contact->GetFixtureB()->GetBody()->GetAngle());
										  if (contains(ud, (const char *)"left"))
										  {
//													 Log("storing left portal data with angle = %.2f\n", angle);
													 p_pos = pos;
													 p_angle = angle;
													 p_isleft = 1;
										  }
										  else
										  {
//													 Log("storing right portal data with angle = %.2f\n", angle);
													 p_pos = pos;
													 p_angle = angle;
													 p_isleft = 0;
										  }
										  /*
										  b2Body * p;
										  if (contains(ud, (const char *)"left"))
										  {
													 Log("creating left portal\n");
													 p = addRect(createPortal.x, createPortal.y, portal_width, portal_height, 0.0f, 0.0f, 2, (char *)"isportal left");
													 p->SetTransform(createPortal, (contact->GetFixtureB()->GetBody()->GetAngle()));
										  }
										  else
										  {
													 Log("creating right portal\n");
													 p = addRect(createPortal.x, createPortal.y, portal_width, portal_height, 0.0f, 0.0f, 2, (char *)"isportal right");
													 p->SetTransform(createPortal, (contact->GetFixtureB()->GetBody()->GetAngle()));
										  }
										  */
								}
								else
								{
										  Log("that's not portalable\n");
								}
								toDestroy = (b2Body *)(contact->GetFixtureA()->GetBody());
					 }
					 else if (contains(ud, (const char *)"isportal"))
					 {
								Log("something hit a portal!\n");
								if ((b2BodyType)(contact->GetFixtureB()->GetBody()->GetType()) == dyn)
								{
										  Log("its a dynamic object\n");
								}
								/*
								else if ((b2BodyType)(contact->GetFixtureB()->GetBody()->GetType()) == stat)
								{
										  Log("hit a static object\n");
								}
								else if ((b2BodyType)(contact->GetFixtureB()->GetBody()->GetType()) == kin)
								{
										  Log("hit a kinematic object\n");
								}
								*/
								else
								{
										  Log("not a dynamic object, don't portal\n");
								}
					 }
		  }
		  ud = (char *)(contact->GetFixtureB()->GetBody()->GetUserData());
		  if (ud)
		  {
					 if (ud == (char *)"player")
					 {
								//								Log("Player hit something\n");
					 }
					 if (contains(ud, (const char *)"bullet"))
					 {
//								Log("bullet hit something\n");
//								Log("FixtureA's user data:\n\t%s\n", ((char *)(contact->GetFixtureA()->GetBody()->GetUserData())));
//								Log("FixtureB's user data:\n\t%s\n", ((char *)(contact->GetFixtureB()->GetBody()->GetUserData())));
								if (contains(((char *)(contact->GetFixtureA()->GetBody()->GetUserData())), "portalable"))
								{
//										  Log("you shot a portalable object!\n");
										  pos = (b2Vec2)(contact->GetFixtureB()->GetBody()->GetWorldCenter());
										  angle = (float)(contact->GetFixtureA()->GetBody()->GetAngle());
										  if (contains(ud, (const char *)"left"))
										  {
//													 Log("storing left portal data with angle = %.2f\n", angle);
													 p_pos = pos;
													 p_angle = angle;
													 p_isleft = 1;
										  }
										  else
										  {
//													 Log("storing right portal data with angle = %.2f\n", angle);
													 p_pos = pos;
													 p_angle = angle;
													 p_isleft = 0;
										  }

										  /*
										  b2Body * p;
										  if (contains(ud, (const char *)"left"))
										  {
													 Log("creating left portal\n");
													 p = addRect(createPortal.x, createPortal.y, portal_width, portal_height, 0.0f, 0.0f, 2, (char *)"isportal left");
													 p->SetTransform(createPortal, (contact->GetFixtureA()->GetBody()->GetAngle()));
										  }
										  else
										  {
													 Log("creating right portal\n");
													 p = addRect(createPortal.x, createPortal.y, portal_width, portal_height, 0.0f, 0.0f, 2, (char *)"isportal right");
													 p->SetTransform(createPortal, (contact->GetFixtureA()->GetBody()->GetAngle()));
										  }
										  */
								}
								else
								{
										  Log("that's not portalable\n");
								}
								toDestroy = (b2Body *)(contact->GetFixtureB()->GetBody());
					 }
					 else if (contains(ud, (const char *)"isportal"))
					 {
								Log("something hit a portal!\n");
								if ((b2BodyType)(contact->GetFixtureA()->GetBody()->GetType()) == dyn)
								{
										  Log("its a dynamic object\n");
								}
								/*
								else if ((b2BodyType)(contact->GetFixtureB()->GetBody()->GetType()) == stat)
								{
										  Log("hit a static object\n");
								}
								else if ((b2BodyType)(contact->GetFixtureB()->GetBody()->GetType()) == kin)
								{
										  Log("hit a kinematic object\n");
								}
								*/
								else
								{
										  Log("not a dynamic object, don't portal\n");
								}
					 }
		  }
}

void contactListener::EndContact (b2Contact * contact)
{
		  char * ud;
		  ud = (char *)(contact->GetFixtureA()->GetBody()->GetUserData());
		  if (ud)
		  {
					 if (ud == (char *)"player")
					 {
								//								Log("Player hit something\n");
					 }
					 if (contains(ud, (const char *)"bullet"))
					 {
//								Log("bullet hit something\n");
								toDestroy = (b2Body *)(contact->GetFixtureA()->GetBody());
					 }
		  }
		  ud = (char *)(contact->GetFixtureB()->GetBody()->GetUserData());
		  if (ud)
		  {
					 if (ud == (char *)"player")
					 {
								//								Log("Player hit something\n");
					 }
					 if (contains(ud, (const char *)"bullet"))
					 {
//								Log("bullet hit something\n");
								toDestroy = (b2Body *)(contact->GetFixtureB()->GetBody());
					 }
		  }
}
