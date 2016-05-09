# In The Name Of God
# ========================================
# [] File Name : light.py
#
# [] Creation Date : 5/9/16
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

from lamp_serial.sys.serial import LampSerial


class Lamp:
    """
    """

    def __init__(self, x: int, y: int):
        self.id = {'x': x, 'y': y}

    def set_light(self, state: bool):
        if state:
            k = 1
        else:
            k = 0
        LampSerial.write_data("L{}{}{}".format(self.id['x'], self.id['y'], k))

    def get_light(self) -> bool:
        pass
