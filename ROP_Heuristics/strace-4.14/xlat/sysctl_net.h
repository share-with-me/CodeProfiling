/* Generated by ./xlat/gen.sh from ./xlat/sysctl_net.in; do not edit. */

#ifdef IN_MPERS

# error static const struct xlat sysctl_net in mpers mode

#else

static
const struct xlat sysctl_net[] = {
 XLAT(NET_CORE),
 XLAT(NET_ETHER),
 XLAT(NET_802),
 XLAT(NET_UNIX),
 XLAT(NET_IPV4),
 XLAT(NET_IPX),
 XLAT(NET_ATALK),
 XLAT(NET_NETROM),
 XLAT(NET_AX25),
 XLAT(NET_BRIDGE),
 XLAT(NET_ROSE),
 XLAT(NET_IPV6),
 XLAT(NET_X25),
 XLAT(NET_TR),
 XLAT(NET_DECNET),
 XLAT(NET_ECONET),
 XLAT(NET_SCTP),
#if defined(NET_LLC) || (defined(HAVE_DECL_NET_LLC) && HAVE_DECL_NET_LLC)
  XLAT(NET_LLC),
#endif
#if defined(NET_NETFILTER) || (defined(HAVE_DECL_NET_NETFILTER) && HAVE_DECL_NET_NETFILTER)
  XLAT(NET_NETFILTER),
#endif
#if defined(NET_DCCP) || (defined(HAVE_DECL_NET_DCCP) && HAVE_DECL_NET_DCCP)
  XLAT(NET_DCCP),
#endif
#if defined(NET_IRDA) || (defined(HAVE_DECL_NET_IRDA) && HAVE_DECL_NET_IRDA)
  XLAT(NET_IRDA),
#endif
 XLAT_END
};

#endif /* !IN_MPERS */
