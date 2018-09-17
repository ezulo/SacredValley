#ifndef EVENT_H
#define EVENT_H

// We will want to expand this later on...
enum EventType { 
	INPUT, 
	STATECHANGE 
};

class Event() {
	public:
		Event(EventType type);
		~Event();
	private:
		EventType type;
}

#endif
