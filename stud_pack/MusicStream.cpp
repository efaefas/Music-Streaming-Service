#include "MusicStream.h"
#include <iostream>

void MusicStream::addProfile(const std::string &email, const std::string &username, SubscriptionPlan plan) {
    /* TODO */
     /* Node<Profile *> *added ; */
     
    Profile* tmp = new Profile(email,username,plan) ;  
    
      profiles.insertAtTheEnd(*tmp);  
   
}

void MusicStream::deleteProfile(const std::string &email) {
    /* TODO */
    for (int i = 0; i < profiles.getSize(); i++)
    {
        if (profiles.getNodeAtIndex(i)->data.getEmail()==email)
        {
            profiles.removeNode(profiles.getNodeAtIndex(i)->data);
        }
        
    }
    
    
}

void MusicStream::addArtist(const std::string &artistName) {
    /* TODO */
    artists.insertAtTheEnd(Artist(artistName));
}

void MusicStream::addAlbum(const std::string &albumName, int artistId) {
    /* TODO */
    Album alb(albumName);
    for (int i = 0; i < artists.getSize(); i++)
    {
       if (artists.getNodeAtIndex(i)->data.getArtistId()==artistId)
       {
        artists.getNodeAtIndex(i)->data.addAlbum(&alb);
        albums.insertAtTheEnd(alb);
        //artisste bi daha bak!
       }
        
    }
    
}

void MusicStream::addSong(const std::string &songName, int songDuration, int albumId) {
    /* TODO */
    Song songg(songName,songDuration);
    for (int i = 0; i < albums.getSize(); i++)
    {
       if (albums.getNodeAtIndex(i)->data.getAlbumId() ==albumId)
       {
        albums.getNodeAtIndex(i)->data.addSong(&songg); 
        songs.insertAtTheEnd(songg);
        //check.!
       }
        
    }

    
//After here check!!!!!

}

void MusicStream::followProfile(const std::string &email1, const std::string &email2) {
    /* TODO */
    for (int i = 0; i < profiles.getSize(); i++)
    {
        if (profiles.getNodeAtIndex(i)->data.getEmail()==email1)

        {
            Profile mainAcc = profiles.getNodeAtIndex(i)->data ;
            LinkedList <Profile*>  mainAccFollowers = mainAcc.getFollowers();
            for (int j = 0; j < profiles.getSize(); j++)
            {
                if (profiles.getNodeAtIndex(j)->data.getEmail()==email2)
                {
                    mainAccFollowers.insertAtTheEnd(&(profiles.getNodeAtIndex(j)->data));
                }
                
            }
            
        }
        
        
        
    }
    
}

//Same mistake!

void MusicStream::unfollowProfile(const std::string &email1, const std::string &email2) {
    /* TODO */
    for (int i = 0; i < profiles.getSize(); i++)
    {
        if (profiles.getNodeAtIndex(i)->data.getEmail()==email1)

        {
            Profile mainAcc = profiles.getNodeAtIndex(i)->data ;
            for (int j = 0; j < mainAcc.getFollowers().getSize() ; j++)
            {
                if (mainAcc.getFollowers().getNodeAtIndex(j)->data->getEmail()==email2)
                {
                    mainAcc.getFollowers().removeNode(mainAcc.getFollowers().getNodeAtIndex(j));
                }
                
            }
            
        }
        
        
        
    }

}

void MusicStream::createPlaylist(const std::string &email, const std::string &playlistName) {
    /* TODO */
    for (int i = 0; i < profiles.getSize(); i++)
    
    {
        if (profiles.getNodeAtIndex(i)->data.getEmail()==email)
        {
            profiles.getNodeAtIndex(i)->data.createPlaylist(playlistName);
        }
        
        
    }
    
}

void MusicStream::deletePlaylist(const std::string &email, int playlistId) {
    /* TODO */
    for (int i = 0; i < profiles.getSize(); i++)
    {
        if (profiles.getNodeAtIndex(i)->data.getEmail()==email){
        profiles.getNodeAtIndex(i)->data.deletePlaylist(playlistId);
    }
    }
}

void MusicStream::addSongToPlaylist(const std::string &email, int songId, int playlistId) {
    /* TODO */
    for (int i = 0; i < profiles.getSize(); i++)
    {
        if (profiles.getNodeAtIndex(i)->data.getEmail()==email)
        {
            for (int j = 0; j <songs.getSize() ; j++)
            {
                if (songs.getNodeAtIndex(j)->data.getSongId()==songId)
                {
                    profiles.getNodeAtIndex(i)->data.addSongToPlaylist(&(songs.getNodeAtIndex(j)->data), playlistId);
                }
                
            }
            
        }
        
        
    }

//Playlist ply = *(getPlaylist(playlistId)); ply.addSong(song);
    
}

void MusicStream::deleteSongFromPlaylist(const std::string &email, int songId, int playlistId) {
    /* TODO */
    
   for (int i = 0; i < profiles.getSize(); i++)
    {
        if (profiles.getNodeAtIndex(i)->data.getEmail()==email)
        {

         LinkedList<Song*> songsss= profiles.getNodeAtIndex(i)->data.getPlaylist(playlistId)->getSongs();

            for (int    j = 0; j < songsss.getSize(); j++)
            {
                if (songsss.getNodeAtIndex(j)->data->getSongId()==songId)
                {
                    profiles.getNodeAtIndex(i)->data.getPlaylist(playlistId)->dropSong(songsss.getNodeAtIndex(j)->data);
                }
                
            }
            
            
        }
        
        
    }
}

LinkedList<Song *> MusicStream::playPlaylist(const std::string &email, Playlist *playlist) {
    /* TODO */

    LinkedList<Song *> enes ;
    return enes;
}

Playlist *MusicStream::getPlaylist(const std::string &email, int playlistId) {
    /* TODO */
     for (int i = 0; i < profiles.getSize(); i++)
    {
        if (profiles.getNodeAtIndex(i)->data.getEmail()==email)
        {
            return profiles.getNodeAtIndex(i)->data.getPlaylist(playlistId); 
        }
        
        
    
    } 
    
}

LinkedList<Playlist *> MusicStream::getSharedPlaylists(const std::string &email) {
    /* TODO */
     for (int i = 0; i < profiles.getSize(); i++)
    {
        if (profiles.getNodeAtIndex(i)->data.getEmail()==email){
            
             return profiles.getNodeAtIndex(i)->data.getSharedPlaylists();

        }
      
    } 

    //Kesin yanlış!!!!!!!!!!!!!!!!!!!!!!!!!! check.
}

void MusicStream::shufflePlaylist(const std::string &email, int playlistId, int seed) {
    /* TODO */
    for (int i = 0; i < profiles.getSize(); i++)
    {
        if (profiles.getNodeAtIndex(i)->data.getEmail()==email){
       profiles.getNodeAtIndex(i)->data.getPlaylist(playlistId)->shuffle(seed);
    }}
    //check!!!!!!!!
    
}

void MusicStream::sharePlaylist(const std::string &email, int playlistId) {
    /* TODO */
     for (int i = 0; i < profiles.getSize(); i++)
    {
         if (profiles.getNodeAtIndex(i)->data.getEmail()==email){
       profiles.getNodeAtIndex(i)->data.sharePlaylist(playlistId);
       
    }}


}

void MusicStream::unsharePlaylist(const std::string &email, int playlistId) {
    /* TODO */
     for (int i = 0; i < profiles.getSize(); i++)
    {
        if (profiles.getNodeAtIndex(i)->data.getEmail()==email){
       profiles.getNodeAtIndex(i)->data.unsharePlaylist(playlistId);
       //Profiledeki shareplayLıst bool döndürüyor. Burda bi daha gerek var mı!!!!!!!
    }}
}

void MusicStream::subscribePremium(const std::string &email) {
    /* TODO */
    for (int i = 0; i < profiles.getSize(); i++)
    {
        if (profiles.getNodeAtIndex(i)->data.getEmail()==email){
        profiles.getNodeAtIndex(i)->data.setPlan(premium);
    }}
    
}

void MusicStream::unsubscribePremium(const std::string &email) {
    /* TODO */
        for (int i = 0; i < profiles.getSize(); i++)
    {
        if (profiles.getNodeAtIndex(i)->data.getEmail()==email){
        profiles.getNodeAtIndex(i)->data.setPlan(free_of_charge);
    }}
    
}

void MusicStream::print() const {
    std::cout << "# Printing the music stream ..." << std::endl;

    std::cout << "# Number of profiles is " << this->profiles.getSize() << ":" << std::endl;
    this->profiles.print();

    std::cout << "# Number of artists is " << this->artists.getSize() << ":" << std::endl;
    this->artists.print();

    std::cout << "# Number of albums is " << this->albums.getSize() << ":" << std::endl;
    this->albums.print();

    std::cout << "# Number of songs is " << this->songs.getSize() << ":" << std::endl;
    this->songs.print();

    std::cout << "# Printing is done." << std::endl;
}
