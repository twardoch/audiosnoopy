from audiosnoopy import audiosnoopy


def test_audiosnoopy():
    info = audiosnoopy("path/to/plugin.vst")
    assert isinstance(info, dict)
    assert "name" in info
    assert "format" in info
    assert "manufacturer" in info
    assert "version" in info
    assert "parameters" in info
