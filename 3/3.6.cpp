//Animal Shelter: An animal shelter, which holds only dogs and cats, operates on a strictly "first in, first
//out" basis. People must adopt either the "oldest" (based on arrival time) of all animals at the shelter,
//or they can select whether they would prefer a dog or a cat (and will receive the oldest animal of
//that type). They cannot select which specific animal they would like. Create the data structures to
//maintain this system and implement operations such as enqueue, dequeueAny, dequeueDog,
//and dequeueCat. You may use the built-in Linked List data structure.


//Built a class which maintain queue 'Animal Shelter' based on Double Linked List and 'Animal' type which collected animal name, arrival time and so on.
class AnimalShelter
{
private:
    string fShelterName;
    struct Animal
    {
    private:
        int ftimestamp;
        string fname;
        //other specificates ...

    public:
        Animal(string name, int timestamp) : fname(name), ftimestamp(timestamp)
        {
        }

        int GetTime()
        {
            return ftimestamp;
        }

        string GetName()
        {
            return fname;
        }
    };

    list<Animal> dog_queue, cat_queue;

public:
    AnimalShelter(string ShelterName) : fShelterName(ShelterName)
    { //ctor
    }

    string GetShelterName()
    {
        return fShelterName;
    }

    void enqueue(string name, int time, int id_animal)
    {

        switch (id_animal)
        {
        case 0: //dog
            dog_queue.emplace_front(name, time);
            break;

        case 1: //cat
            cat_queue.emplace_front(name, time);
            break;
        }
    }

    Animal dequeueAny() //based on time arrival dequeue oldest dog/cat
    {

        if (dog_queue.empty() && !cat_queue.empty())
            return dequeueCat();
        if (cat_queue.empty() && !dog_queue.empty())
            return dequeueDog();

        //   if(dog_queue.empty() && cat_queue.empty()) asset TODO

        Animal &oldest_dog = dog_queue.back();
        Animal &oldest_cat = cat_queue.back();

        return oldest_dog.GetTime() < oldest_cat.GetTime() ? dequeueDog() : dequeueCat(); //if time is equal is edge case and could be TODO about it
    }

    Animal dequeueDog() //copy oldest item and pop this item from DLL
    {
        //if(dog_queue.empty()) asset TODO

        Animal oldest_dog = dog_queue.back();
        dog_queue.pop_back();
        return oldest_dog;
    }

    Animal dequeueCat()
    {
     //if(cat_queue.empty()) asset TODO

        Animal oldest_cat = cat_queue.back();
        cat_queue.pop_back();
        return oldest_cat;
    }
};
