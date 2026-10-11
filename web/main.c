#include "mongoose.h"
#include <stdio.h>

// 1. Updated: fn now takes exactly 3 arguments to fix the callback type error
static void fn(struct mg_connection *c, int ev, void *ev_data)
{
    if (ev == MG_EV_HTTP_MSG)
    {
        struct mg_http_message *hm = (struct mg_http_message *)ev_data;

        // 2. Updated: Replaced mg_http_match_uri with mg_match
        if (mg_match(hm->uri, mg_str("/"), NULL))
        {
            mg_http_reply(c, 200, "Content-Type: text/html\r\n", "api is running...");
        }
        else if (mg_match(hm->uri, mg_str("/health"), NULL))
        {
            mg_http_reply(c, 200, "Content-Type: application/json\r\n",
                          "{\"status\": \"ok\"}");
        }
        else
        {
            mg_http_reply(c, 404, "Content-Type: application/json\r\n",
                          "{\"error\": \"Not Found\"}");
        }
    }
}

int main()
{
    struct mg_mgr mgr;
    mg_mgr_init(&mgr); // Init manager

    // This will now pass cleanly because fn has the correct signature
    mg_http_listen(&mgr, "http://localhost:8080", fn, NULL);

    printf("REST API running on http://localhost:8080\n");
    while (true)
    {
        mg_mgr_poll(&mgr, 1000); // Infinite event loop
    }

    mg_mgr_free(&mgr);
    return 0;
}
