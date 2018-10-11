#ifndef HEADER_GUARD
#define HEADER_GUARD
#include <string>

class Celebrity {
	public:
		Celebrity();
		~Celebrity();

		Celebrity(std::string name,
				int meet_rating,
				bool met);

		Celebrity(std::string name,
				int meet_rating,
				std::string area,
				bool met);
		
		std::string get_name() const;
		int get_meet_rating() const;
		std::string get_area() const;
		bool get_met() const;

		void set_name(std::string name);
		void set_meet_rating(int meet_rating);
		void set_area(std::string area);
		void set_met(bool met);
		friend bool operator< (const Celebrity & c1, const Celebrity & c2);
		friend bool operator<= (const Celebrity & c1, const Celebrity & c2);
//		bool operator< (Celebrity & c);
//		bool operator<= (Celebrity & c);

	private:
		std::string name;
		int meet_rating;
		std::string area;
		bool met;
};
#endif
