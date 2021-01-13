
#include<unordered_map>
#include<map>
#include<string>
#include<vector>
#include<iostream>

using namespace std;

map<string, vector<string>> getUserFavouriteGenres(map<string, vector<string>> userSongs, map<string, vector<string>> songGenres){
	map<string, vector<string>> userFavGenres;

	map<string, string> songToGenre; // maps the song name to its genre
	for (auto it = songGenres.begin(); it != songGenres.end(); ++it){
		string genre = it->first;
		vector<string> songs = it->second;

		for (string song : songs){
			songToGenre[song] = genre;
		}
	}

	for (auto it = userSongs.begin(); it != userSongs.end(); ++it){
		string user = it->first;
		vector<string> userFavSongs = it->second;
		unordered_map<string, int> songGenresCount;
		int maxCount = 0;
		for (string song : userFavSongs){
			string songGenre = songToGenre[song];
			songGenresCount[songGenre]++;
			maxCount = max(maxCount, songGenresCount[songGenre]);
		}

		for (auto ii = songGenresCount.begin(); ii != songGenresCount.end(); ++ii){
			if(ii->second == maxCount){
				if(userFavGenres.find(user) == userFavGenres.end())
					userFavGenres[user] = {};
				userFavGenres[user].push_back(ii->first);		
			}
		}
	}
	return userFavGenres;
}

int main(void){
	map<string, vector<string>> userSongs;
	map<string, vector<string>> songGenres;

	userSongs["David"] = {"song1", "song2", "song3", "song4", "song8"};
	userSongs["Emma"] = {"song5", "song6", "song7"};

	songGenres["Rock"] = {"song1", "song3"};
	songGenres["Dubstep"] = {"song7"};
	songGenres["Techno"] = {"song2", "song4"};
	songGenres["Pop"] = {"song5", "song6"};
	songGenres["Jazz"] = {"song8", "song9"};

	map<string, vector<string>> result = getUserFavouriteGenres(userSongs, songGenres);
	for (auto it = result.begin(); it != result.end(); ++it){
		cout << it->first << ": ";
		for (string g : it->second){
			cout << g << ", ";
		}
		cout << endl;
	}

	return 0;
}
