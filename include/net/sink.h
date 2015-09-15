/*
 * net/sink.h	Protocol independent lightweight packet sink.
 *
 * Authors:	Eric Biederman <ebiederm@xmission.com>
 */
#ifndef _NET_SINK_H
#define _NET_SINK_H

#include <linux/netdev_features.h>

struct sink;
struct header_ops;
struct neigh_parms;
struct seq_file;

struct sink_ops {
	int				(*sink_output)(struct sink *, struct sk_buff *);
	void				(*sink_hold)(struct sink *);
	void				(*sink_put)(struct sink *);
	struct net *			(*sink_net)(struct sink *);
	struct net_device *		(*sink_dev)(struct sink *);
	const struct header_ops *	(*sink_header_ops)(struct sink *);
	struct neigh_parms *		(*sink_arp_parms)(struct sink *);
	unsigned int			(*sink_type)(struct sink *sink);
	unsigned int			(*sink_hh_len)(struct sink *);
	unsigned int			(*sink_mtu)(struct sink *);
	int				(*sink_ifindex)(struct sink *);
	unsigned short			(*sink_ha_type)(struct sink *);
	unsigned char			(*sink_ha_len)(struct sink *);
	unsigned char *			(*sink_ha_addr)(struct sink *);
	unsigned char *			(*sink_ha_broadcast)(struct sink *);
	netdev_features_t		(*sink_features)(struct sink *);
	int				(*sink_seq_name)(struct seq_file *, struct sink *);
};

struct sink {
	const struct sink_ops *ops;
};

static inline int sink_output(struct sink *sink, struct sk_buff *skb)
{
	return sink->ops->sink_output(sink, skb);
}

static inline void sink_hold(struct sink *sink)
{
	return sink->ops->sink_hold(sink);
}

static inline void sink_put(struct sink *sink)
{
	return sink->ops->sink_put(sink);
}

static inline struct net *sink_net(struct sink *sink)
{
	return sink->ops->sink_net(sink);
}

static inline struct net_device *sink_dev(struct sink *sink)
{
	return sink->ops->sink_dev(sink);
}

static inline const struct header_ops *sink_header_ops(struct sink *sink)
{
	return sink->ops->sink_header_ops(sink);
}

static inline struct neigh_parms *sink_arp_parms(struct sink *sink)
{
	return sink->ops->sink_arp_parms(sink);
}

static inline unsigned int sink_type(struct sink *sink)
{
	return sink->ops->sink_type(sink);
}

static inline unsigned int sink_hh_len(struct sink *sink)
{
	return sink->ops->sink_hh_len(sink);
}

static inline unsigned int sink_mtu(struct sink *sink)
{
	return sink->ops->sink_mtu(sink);
}

static inline int sink_ifindex(struct sink *sink)
{
	return sink->ops->sink_ifindex(sink);
}

static inline unsigned short sink_ha_type(struct sink *sink)
{
	return sink->ops->sink_ha_type(sink);
}

static inline unsigned char sink_ha_len(struct sink *sink)
{
	return sink->ops->sink_ha_len(sink);
}

static inline unsigned char *sink_ha_addr(struct sink *sink)
{
	return sink->ops->sink_ha_addr(sink);
}

static inline unsigned char *sink_ha_broadcast(struct sink *sink)
{
	return sink->ops->sink_ha_broadcast(sink);
}

static inline netdev_features_t sink_features(struct sink *sink)
{
	return sink->ops->sink_features(sink);
}

static inline int sink_seq_name(struct seq_file *seq, struct sink *sink)
{
	return sink->ops->sink_seq_name(seq, sink);
}

#endif /* _NET_SINK_H */
