"""LCM type definitions
This file automatically generated by lcm.
DO NOT MODIFY BY HAND!!!!
"""

try:
    import cStringIO.StringIO as BytesIO
except ImportError:
    from io import BytesIO
import struct

class test_signal_lcmt(object):
    __slots__ = ["pos", "rpy", "q_knee", "q_hip", "timestep"]

    __typenames__ = ["float", "float", "float", "float", "float"]

    __dimensions__ = [None, None, None, None, None]

    def __init__(self):
        self.pos = 0.0
        self.rpy = 0.0
        self.q_knee = 0.0
        self.q_hip = 0.0
        self.timestep = 0.0

    def encode(self):
        buf = BytesIO()
        buf.write(test_signal_lcmt._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        buf.write(struct.pack(">fffff", self.pos, self.rpy, self.q_knee, self.q_hip, self.timestep))

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != test_signal_lcmt._get_packed_fingerprint():
            raise ValueError("Decode error")
        return test_signal_lcmt._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = test_signal_lcmt()
        self.pos, self.rpy, self.q_knee, self.q_hip, self.timestep = struct.unpack(">fffff", buf.read(20))
        return self
    _decode_one = staticmethod(_decode_one)

    _hash = None
    def _get_hash_recursive(parents):
        if test_signal_lcmt in parents: return 0
        tmphash = (0xf118f1fd346cc493) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff) + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if test_signal_lcmt._packed_fingerprint is None:
            test_signal_lcmt._packed_fingerprint = struct.pack(">Q", test_signal_lcmt._get_hash_recursive([]))
        return test_signal_lcmt._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)

