#include <iostream>
#include <list>
using namespace std;

class ISubscriber
{
public:
  virtual void notify(string msg) = 0;
};

class User : public ISubscriber
{
private:
  int user_id;

public:
  User(int user_id)
  {
    this->user_id = user_id;
  }

  void notify(string msg)
  {
    cout << this->user_id << " " << msg << endl;
  }
};

class Group
{
private:
  list<ISubscriber *> users;

public:
  void subscriber(ISubscriber *user)
  {
    users.push_back(user);
  }

  void unsubscribe(ISubscriber *user)
  {
    users.remove(user);
  }

  void notify(string msg)
  {
    for (auto user : users)
    {
      user->notify(msg);
    }
  }
};

int main()
{
  Group *group = new Group();

  User *user1 = new User(1);
  User *user2 = new User(2);
  User *user3 = new User(3);

  group->subscriber(user1);
  group->subscriber(user2);
  group->subscriber(user3);

  group->notify("new notification");

  group->unsubscribe(user1);
  group->notify("second notification");

  return 0;
}