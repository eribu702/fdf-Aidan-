/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroberts <aroberts@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:15:02 by aroberts          #+#    #+#             */
/*   Updated: 2023/11/14 15:33:29 by aroberts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* key handler takes a key, and a void *param, which is a pointer to
a data type, it allows for any data type to be put through. what is coming
through is a t_fdf *fdf, so we initalize a fdf and set it to (t_fdf *)param.
we also initalize a new node on our hook list, *event. we then set event to
fdf->events, and iterate through it with a while loop until the key that we have
pressed matches a key in a node on our linked list. we then call the associated
function with the parameters: the key we pressed and fdf.
((event->function)(key, fdf))
we then refresh the rendering, and break.
finnaly we return (0) to tell mlx_hook() that we have handled our key.
 */
int	key_handler(int key, void *param)
{
	t_hook	*event;
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	event = fdf->events;
	while (event)
	{
		if (key == event->key_press)
		{
			(event->function)(key, fdf);
			render_fdf(fdf);
			break ;
		}
		event = event->next;
	}
	return (0);
}

/* add hook takes a **events which is a double pointer used for linked lists.
it takes a key and a function, and creates a 'hook'. it is a static void
so that this same function retains the hooks it creates and can be used
whenever. it creates a new instance of the hook struct for this new event,
and *curr, which means current and is used to traverse this linked list.
new_event is malloced to make sure it is empty and avoids segfaults,
new_event.key_press is set to the key, new_event.function is set to that
key's corresponding function, and new_event.next is set to NULL, this is
temporary until add_hook is used again, and ensures that this linked list
ends with a NULL. if thee is no current event then we clear this event we have
created by making it = a new_event, otherwise we continue with the function
to our while loop, our while loop
while (curr->next)
	curr = curr->next;
curr = new_event;
is more easily understood as 
while (current.next != NULL)
	go to next node on list
current = new_event.
this basicly iterates through the list until it finds the last node
where curr.next == NULL and then sets current to new_event, which correctly
links the hook we have just created to the end of our list.*/
static void	add_hook(t_hook **events, int key, void (*f)())
{
	t_hook	*new_event;
	t_hook	*curr;

	curr = *events;
	new_event = (t_hook *)malloc(sizeof(t_hook));
	if (!new_event)
		terminate(gen_error_msg(ERR, MALLOC), 1);
	new_event->key_press = key;
	new_event->function = f;
	new_event->next = NULL;
	if (!curr)
		(*events) = new_event;
	else
	{
		{
			while (curr->next)
				curr = curr->next;
			curr = new_event;
		}
	}
}

static void	load_keys(t_hook **events)
{
	add_hook(events, 53, destroy);
}

/* mlx hook one takes 2, so its a keypress, and 1L << 0 is a mask that makes
the hook look for key presses only, if this goes througj it will run key_handler
with the key that was pressed.
hook 2 takes 17 (destroy notify), with 1L << 17 (structure notify)
that is a mask that looks for any change to the window structure. this one
handles closing the window.  */
void	load_event_hooks(t_fdf *fdf)
{
	t_hook	*events;

	events = NULL;
	load_keys(&events);
	mlx_hook(fdf->win, 2, 1L << 0, key_handler, fdf);
	mlx_hook(fdf->win, 17, 1L << 17, x_close_win, fdf);
	fdf->events = events;
}
