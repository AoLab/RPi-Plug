/*
 * In The Name Of God
 * ========================================
 * [] File Name : route.c
 *
 * [] Creation Date : 15-03-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/

#include <libsoup/soup.h>

#include "route.h"

static void on_OnI_event_callback(SoupServer *server,
		SoupMessage *msg,
		const char *path,
		GHashTable *query,
		SoupClientContext *client,
		gpointer user_data)
{
	g_message("Start handling request for %s", path);

	/*
	 * You must enter the URL currectly we do not
	 * handle /Lamp/OnI/foo or ... in this function.
	 * We response to invalid URLs with NOT FOUND.
	*/
	if (g_strcmp0(path, "/Lamp/OnI")) {
		soup_message_set_status(msg, SOUP_STATUS_NOT_FOUND);
		g_message("Invalid path: %s instead of /Lamp/OnI", path);
		return;
	}

	/*
	 * We have OnI function with GET method ONLY :)
	 * so you get NOT IMPLEMENTED error with use other method
	 * on it.
	*/
	if (msg->method != SOUP_METHOD_GET) {
		soup_message_set_status(msg, SOUP_STATUS_NOT_IMPLEMENTED);
		g_message("Invalid method: %s instead of GET", msg->method);
		return;
	}

	g_message("Request Interval: %s", (const char *)g_hash_table_lookup(query, "interval"));
	soup_message_set_status(msg, SOUP_STATUS_OK);
}

static void default_event_callback(SoupServer *server,
		SoupMessage *msg,
		const char *path,
		GHashTable *query,
		SoupClientContext *client,
		gpointer user_data)
{
	g_message("404 NotFound: %s", path);
	soup_message_set_status(msg, SOUP_STATUS_NOT_FOUND);
}


void rest_route_init(SoupServer *server)
{
	soup_server_add_handler(server, "/Lamp/OnI",
			on_OnI_event_callback, NULL, NULL);
	soup_server_add_handler(server, NULL,
			default_event_callback, NULL, NULL);
}
