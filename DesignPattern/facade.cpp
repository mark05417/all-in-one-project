#include <iostream>
#include <string>


class Decoder {
public:
    void decode(const std::string& file) {
        std::cout << "Decoding " << file << std::endl;
    }
};

class Encoder {
public:
    void encode(const std::string& format) {
        std::cout << "Encoding to " << format << std::endl;
    }
};

class Compressor {
public:
    void compress() {
        std::cout << "Compressing video" << std::endl;
    }
};

class AudioProcessor {
public:
    void processAudio() {
        std::cout << "Processing audio..." << std::endl;
    }
};

class SubtitleHandler {
public:
    void addSubtitle(const std::string& subtitleFile) {
        std::cout << "Adding subtitle: " << subtitleFile << std::endl;
    }
};

class ResolutionAdjuster {
public:
    void adjustResolution(int width, int height) {
        std::cout << "Adjusting resolution to " << width << "x" << height << std::endl;
    }
};

class VideoConverterFacade {
private:
    Decoder decoder;
    Encoder encoder;
    Compressor compressor;
    AudioProcessor audioProcessor;
    SubtitleHandler subtitleHandler;
    ResolutionAdjuster resolutionAdjuster;

public:
    void convertVideo(const std::string& file, const std::string& format,
        const std::string& subtitleFile, int width, int height) {

        decoder.decode(file);                      
        audioProcessor.processAudio();             
        subtitleHandler.addSubtitle(subtitleFile); 
        resolutionAdjuster.adjustResolution(width, height);
        compressor.compress();                     
        encoder.encode(format);                    
    }
};


int main() {
    VideoConverterFacade facade;
    facade.convertVideo("movie.mp4", "avi", "movie.srt", 640, 480);
    return 0;
}