
#ifndef SOUNDKONVERTER_CODEC_WAVPACK_H
#define SOUNDKONVERTER_CODEC_WAVPACK_H

#include "../../core/codecplugin.h"

class ConversionOptions;


class soundkonverter_codec_wavpack : public CodecPlugin
{
    Q_OBJECT
public:
    /** Default Constructor */
    soundkonverter_codec_wavpack( QObject *parent, const QStringList& args );

    /** Default Destructor */
    ~soundkonverter_codec_wavpack();

    QString name() const;

    QList<ConversionPipeTrunk> codecTable();

    bool isConfigSupported( ActionType action, const QString& codecName );
    void showConfigDialog( ActionType action, const QString& codecName, QWidget *parent );
    bool hasInfo();
    void showInfo( QWidget *parent );

    CodecWidget *newCodecWidget();

    unsigned int convert( const KUrl& inputFile, const KUrl& outputFile, const QString& inputCodec, const QString& outputCodec, const ConversionOptions *_conversionOptions, TagData *tags = 0, bool replayGain = false );
    QStringList convertCommand( const KUrl& inputFile, const KUrl& outputFile, const QString& inputCodec, const QString& outputCodec, const ConversionOptions *_conversionOptions, TagData *tags = 0, bool replayGain = false );
    float parseOutput( const QString& output );
};

K_EXPORT_SOUNDKONVERTER_CODEC( wavpack, soundkonverter_codec_wavpack )


#endif // _SOUNDKONVERTER_CODEC_WAVPACK_H_


