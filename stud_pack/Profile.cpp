#include "Profile.h"

Profile::Profile(const std::string &email, const std::string &username, SubscriptionPlan plan) {
    this->email = email;
    this->username = username;
    this->plan = plan;
}

const std::string &Profile::getUsername() const {
    return this->username;
}

const std::string &Profile::getEmail() const {
    return this->email;
}

SubscriptionPlan Profile::getPlan() const {
    return this->plan;
}

LinkedList<Playlist> &Profile::getPlaylists() {
    return this->playlists;
}

LinkedList<Profile *> &Profile::getFollowings() {
    return this->following;
}

LinkedList<Profile *> &Profile::getFollowers() {
    return this->followers;
}

void Profile::setPlan(SubscriptionPlan plan) {
    this->plan = plan;
}

void Profile::followProfile(Profile *profile) {
    /* TODO */
    following.insertAtTheEnd(profile);

}

void Profile::unfollowProfile(Profile *profile) {
    /* TODO */
    following.removeNode(profile);
    //2.2.15 check!
}

void Profile::createPlaylist(const std::string &playlistName) {
    /* TODO */
    playlists.insertAtTheEnd(Playlist(playlistName));
}

void Profile::deletePlaylist(int playlistId) {
    /* TODO */
    Playlist ply = *(getPlaylist(playlistId));
    playlists.removeNode(ply);
   //2.2.15

}

void Profile::addSongToPlaylist(Song *song, int playlistId) {
    /* TODO */
    Playlist ply = *(getPlaylist(playlistId));
    ply.addSong(song);


}

void Profile::deleteSongFromPlaylist(Song *song, int playlistId) {
    /* TODO */
    Playlist ply = *(getPlaylist(playlistId));
    ply.dropSong(song);
}

Playlist *Profile::getPlaylist(int playlistId) {
    /* TODO */
    for (int i = 0; i < playlists.getSize(); i++)
    {
        int id=playlists.getNodeAtIndex(i)->data.getPlaylistId();

    if (id==playlistId)
    {
        return &(playlists.getNodeAtIndex(i)->data);
    }
    
    }
    
}

LinkedList<Playlist *> Profile::getSharedPlaylists() {
    /* TODO */
    LinkedList<Playlist *> result;
    for (int i = 0; i < following.getSize() ; i++)
    {
        int plSize = following.getNodeAtIndex(i)->data->getPlaylists().getSize();

        for (int j = 0; j < plSize; j++)
        {
            Playlist* pl = &(following.getNodeAtIndex(i)->data->getPlaylists().getNodeAtIndex(j)->data);
            
            if (pl->isShared())
            {
                result.insertAtTheEnd(pl);
            }
            
                
        }
        
    }
    return result;
}

void Profile::shufflePlaylist(int playlistId, int seed) {
    /* TODO */
    getPlaylist(playlistId)->shuffle(seed);
}

void Profile::sharePlaylist(int playlistId) {
    /* TODO */
    getPlaylist(playlistId)->setShared(true);

}

void Profile::unsharePlaylist(int playlistId) {
    /* TODO */
    getPlaylist(playlistId)->setShared(false);

}

bool Profile::operator==(const Profile &rhs) const {
    return this->email == rhs.email && this->username == rhs.username && this->plan == rhs.plan;
}

bool Profile::operator!=(const Profile &rhs) const {
    return !(rhs == *this);
}

std::ostream &operator<<(std::ostream &os, const Profile &profile) {
    os << "email: " << profile.email << " |";
    os << " username: " << profile.username << " |";
    if (profile.plan == free_of_charge) {
        os << " plan: " << "free_of_charge" << " |";
    } else if (profile.plan == premium) {
        os << " plan: " << "premium" << " |";
    } else {
        os << " plan: " << "undefined" << " |";
    }

    os << " playlists: [";
    Node<Playlist> *firstPlaylistNode = profile.playlists.getFirstNode();
    Node<Playlist> *playlistNode = firstPlaylistNode;
    if (playlistNode) {
        do {
            os << playlistNode->data;
            if (playlistNode->next != firstPlaylistNode) os << ", ";
            playlistNode = playlistNode->next;
        } while (playlistNode != firstPlaylistNode);
    }
    os << "] |";
    os << " following: [";
    Node<Profile *> *firstProfileNode = profile.following.getFirstNode();
    Node<Profile *> *profileNode = firstProfileNode;
    if (profileNode) {
        do {
            os << profileNode->data->getEmail();
            if (profileNode->next != firstProfileNode) os << ", ";
            profileNode = profileNode->next;
        } while (profileNode != firstProfileNode);
    }
    os << "] |";
    os << " followers: [";
    firstProfileNode = profile.followers.getFirstNode();
    profileNode = firstProfileNode;
    if (profileNode) {
        do {
            os << profileNode->data->getEmail();
            if (profileNode->next != firstProfileNode) os << ", ";
            profileNode = profileNode->next;
        } while (profileNode != firstProfileNode);
    }
    os << "]";

    return os;
}
