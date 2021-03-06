//
//  session.h
//  libtorrent-js
//
//  Created by Patricio Villalobos on 3/23/13.
//
//

#ifndef __libtorrent_js__session__
#define __libtorrent_js__session__

#include <iostream>

#include <node.h>
#include <v8.h>
#include <libtorrent/session.hpp>

#include "event_dispatcher.hpp"

using namespace v8;


namespace libtorrentjs {
    
    class Session : public node::ObjectWrap {
        
        libtorrent::session _session;
        
        event_dispatcher dispatcher;
        
        static v8::Handle<v8::Value> New(const Arguments& args);
        static Persistent<Function> constructor;
        
        // functions wraping function in the libtorrent session objects
        static v8::Handle<v8::Value> load_state(const Arguments& args);
        static v8::Handle<v8::Value> save_state(const Arguments& args);
        
        static v8::Handle<v8::Value> listen_on(const Arguments& args);
        static v8::Handle<v8::Value> add_torrent(const Arguments& args);
        static v8::Handle<v8::Value> post_torrent_updates(const Arguments& args);
        static v8::Handle<v8::Value> get_alerts(const Arguments& args);
        static v8::Handle<v8::Value> on(const Arguments& args);
        
        static v8::Handle<v8::Value> start_dht(const Arguments& args);
        static v8::Handle<v8::Value> stop_dht(const Arguments& args);
        static v8::Handle<v8::Value> set_dht_settings(const Arguments& args);
        static v8::Handle<v8::Value> is_dht_running(const Arguments& args);
        
        static v8::Handle<v8::Value> add_dht_router(const Arguments& args);

        
        
    public:
        
        
        
        static void Init();
        static v8::Handle<v8::Value> NewInstance(const Arguments& args);
        
        Session();
        ~Session();
        
    };
    
};

#endif /* defined(__libtorrent_js__session__) */
